using System.Collections.Generic;

namespace DocsReport {

    class SuffixTree<TChar> where TChar : IComparable<TChar>, IComparable<int>
    {
        public class Node
        {
            public SortedDictionary<TChar, Node> Next { get; set; }
            public SortedDictionary<TChar, Node> Link { get; set; }
            public Node? Parent { get; set; }

            public Node() {
                Next = new SortedDictionary<TChar, Node>();
                Link = new SortedDictionary<TChar, Node>();
            }

            public int Begin { get; set; }
            public int End { get; set; }
            public int Length { get { return End - Begin; } }
            public bool Mark { get; set; }
            public int PathLength { get; set; }

            // Leaf properties
            public int DocumentId {get; set; }
            public int Position {get; private set; }

            public List<Node> Traverse(int pathLength) {
                if (Next.Count == 0) {
                    Position = pathLength;
                    return new List<Node>() { this };
                }

                var result = new List<Node>();
                foreach (var node in Next.Values) {
                    result.AddRange(node.Traverse(pathLength + node.Length));
                }

                return result;
            }
        }

        public Node Root { get; private set; }
        private Node fake;

        IReadOnlyList<TChar> input;

        public SuffixTree(IReadOnlyList<TChar> input, 
            IEnumerable<TChar> inputAlphabet, SortedDictionary<int, string> documentIds) {

                fake = new Node { Mark = false };
                Root = new Node { Parent = fake, Begin = 0, End = 1, Mark = true };

                this.input = input;

                foreach (var c in inputAlphabet)
                    fake.Next[c] = fake.Link[c] = Root;

                List<int> ids = documentIds.Select(p => p.Key).ToList();
                var idIndex = -1;

                var last = Root;
                for (int i = input.Count - 1; i >= 0; i--)
                {                   
                    if (input[i].CompareTo(256) >= 0) {
                        idIndex++;
                    }
                    last = Extend(input[i], input, last, ids[idIndex]);
                }
        }

        private Node Extend(TChar c, IReadOnlyList<TChar> input, Node last, int documentId)
        {
            Node v, w;
            int i = input.Count;
            for (v = last; !v.Link.TryGetValue(c, out w); v = v.Parent)
                i -= v.Length;
            if (w.Next.TryGetValue(input[i], out Node u))
            {
                int j = u.Begin;
                for (; EqualityComparer<TChar>.Default.Equals(input[j], input[i]); j += v.Length, i += v.Length)
                    v = v.Next[input[i]];
                var split = new Node { Parent = w, Begin = u.Begin, End = j, Mark = false };
                w.Next[input[u.Begin]] = split;    // split the edge w->u
                u.Begin = j;
                split.Next[input[j]] = u;
                w = u.Parent = v.Link[c] = split;	// prefix-link to the new node
            }
            last = last.Link[c] = new Node { Parent = w, Begin = i, 
                                             End = input.Count, Mark = true, DocumentId = documentId };
            return w.Next[input[i]] = last;		// attach new leaf to w
        }

        public bool TryGetSubtree(List<TChar> pattern, out Node? subtree) 
        {
            var v = Root;
            subtree = null;
            var pathLength = 0;

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

                if (i == pattern.Count) {
                    v.PathLength = pathLength;
                    subtree = v;
                    return true;
                }

                pathLength += v.Length;
            }

            return false;
        }
    }
}