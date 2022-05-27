using System.Collections.Generic;

namespace DocsReport {

    class SuffixTree<TChar> where TChar : IComparable<TChar>
    {
        public class Node
        {
            public SortedDictionary<TChar, Node> Next { get; set; } 
                = new SortedDictionary<TChar, Node>();

            public SortedDictionary<TChar, Node> Link { get; set; } 
                = new SortedDictionary<TChar, Node>();
                
            public Node Parent { get; set; }

            public int Begin { get; set; }
            public int End { get; set; }
            public int Length { get { return End - Begin; } }
            public bool Mark { get; set; }

            // defined only for leafs
            public DocumentInfo DocumentInfo {get; set; }
            public int PathLengthToReach {get; private set; }

            public IEnumerable<Node> Traverse(int pathLengthToReachNode) {

                if (Next.Count == 0) {
                    PathLengthToReach = pathLengthToReachNode;
                    yield return this;
                }

                var leafs = Next.Values.Select(
                    neighbour => neighbour.Traverse(pathLengthToReachNode + neighbour.Length));

                foreach (var leaf in leafs.SelectMany(p => p)) {
                    yield return leaf;
                }
            }
        }

        public Node Root { get; private set; }
        private Node fake;

        IReadOnlyList<TChar> input;

        public SuffixTree(IReadOnlyList<TChar> input, IEnumerable<TChar> inputAlphabet, 
            Func<TChar, bool> isNotAlphabetSymbol, List<DocumentInfo> documentsInfo) {

                fake = new Node { Mark = false };
                Root = new Node { Parent = fake, Begin = 0, End = 1, Mark = true };

                this.input = input;

                foreach (var c in inputAlphabet)
                    fake.Next[c] = fake.Link[c] = Root;

                var idIndex = documentsInfo.Count;

                var last = Root;
                for (int i = input.Count - 1; i >= 0; i--)
                {                   
                    if (isNotAlphabetSymbol(input[i])) {
                        idIndex--;
                    }
                    last = Extend(input[i], input, last, documentsInfo[idIndex]);
                }
        }

        private Node Extend(
            TChar c, IReadOnlyList<TChar> input, Node last, DocumentInfo documentInfo)
        {
            Node v, w;
            int i = input.Count;
            for (v = last; !v.Link.TryGetValue(c, out w); v = v.Parent)
                i -= v.Length;
            if (w.Next.TryGetValue(input[i], out Node u))
            {
                int j = u.Begin;
                for (; EqualityComparer<TChar>.Default.Equals(input[j], input[i]); 
                       j += v.Length, i += v.Length)
                    v = v.Next[input[i]];
                var split = new Node { Parent = w, Begin = u.Begin, End = j, Mark = false };
                w.Next[input[u.Begin]] = split;    // split the edge w->u
                u.Begin = j;
                split.Next[input[j]] = u;
                w = u.Parent = v.Link[c] = split;	// prefix-link to the new node
            }
            last = last.Link[c] = new Node { Parent = w, Begin = i, 
                                             End = input.Count, Mark = true, DocumentInfo = documentInfo };
            return w.Next[input[i]] = last;		// attach new leaf to w
        }

        public bool TryGetSubtree(
            List<TChar> pattern, out Node? subtree, out int pathLengthToReachSubtree) 
        {
            subtree = null;
            pathLengthToReachSubtree = 0;

            var v = Root;

            for (var i = 0; i < pattern.Count; ) {

                if (!v.Next.ContainsKey(pattern[i])) {
                    return false;
                }

                v = v.Next[pattern[i]];

                for (var j = v.Begin; j < v.Length + v.Begin && i < pattern.Count; i++, j++) {
                    if (!EqualityComparer<TChar>.Default.Equals(pattern[i], input[j])) {
                        return false;
                    }
                }

                pathLengthToReachSubtree += v.Length;

                if (i == pattern.Count) {
                    subtree = v;
                    return true;
                }     
            }

            return false;
        }
    }
}