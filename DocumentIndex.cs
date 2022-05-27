using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DocsReport
{
	class ReverseComparer<T> : IComparer<T> where T : IComparable {
		public int Compare(T x, T y)
        {
            return -1 * x.CompareTo(y);
        }
	}

	class DocumentOccurrences
	{
		public string? DocumentKey { get; set; }
		public List<int>? OccurrencePositions { get; set; }
	}
    
	class DocumentIndex
	{
		private SortedDictionary<int, string> documentIds;
		private SuffixTree<int> tree;
		private List<int> input;

		public DocumentIndex(IReadOnlyList<KeyValuePair<string, byte[]>> documents)
		{
			documentIds = new SortedDictionary<int, string>(new ReverseComparer<int>());
			var documentId = 0;  // document start position in input
			foreach (var document in documents) {
				documentIds[documentId] = document.Key;
				documentId += document.Value.Length + 1;
			}

			var intCast = documents.Select(d => d.Value.Select(x => (int)x)).ToList();
			var inputAlphabet = Enumerable.Range(0, 256 + intCast.Count);
			input = intCast.SelectMany((d, i) => d.Concat(new[] { 256 + i })).ToList();
			tree = new SuffixTree<int>(input, inputAlphabet, documentIds);
		}

		public List<DocumentOccurrences> ReportOccurrences(byte[] pattern)
		{
			var w = pattern.Select(x => (int)x).ToList();

			var subtree = new SuffixTree<int>.Node();	
			if (!tree.TryGetSubtree(w, out subtree)) {
				return new List<DocumentOccurrences>();
			}

			var occurences = new Dictionary<string, List<int>>();
			var leafs = subtree.Traverse(subtree.PathLength + subtree.Length);

			foreach (var leaf in leafs) {
				var documentKey = documentIds[leaf.DocumentId];
				if (!occurences.ContainsKey(documentKey)) {
					occurences[documentKey] = new List<int>();
				}
				occurences[documentKey].Add(input.Count - leaf.Position - leaf.DocumentId);
			}

			return occurences.Select(
				p => new DocumentOccurrences() {
					DocumentKey = p.Key, OccurrencePositions = p.Value}).ToList();
		}
	}
}