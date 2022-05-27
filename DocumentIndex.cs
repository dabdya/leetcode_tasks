using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DocsReport
{
	class DocumentOccurrences
	{
		public string DocumentKey { get; set; }
		public List<int> OccurrencePositions { get; set; }
	}

	class DocumentInfo 
	{
		public int StartPositionInInput { get; set; }
		public string Key { get; set; }
	}
    
	class DocumentIndex
	{
		private List<DocumentInfo> documentsInfo;
		private SuffixTree<int> tree;
		private List<int> input;

		public DocumentIndex(IReadOnlyList<KeyValuePair<string, byte[]>> documents)
		{
			documentsInfo = new List<DocumentInfo>();
			var startPosition = 0;
			foreach (var document in documents) {
				documentsInfo.Add(new DocumentInfo() { 
					StartPositionInInput = startPosition, Key = document.Key});
				startPosition += document.Value.Length + 1;
			}

			var intCast = documents.Select(d => d.Value.Select(x => (int)x)).ToList();
			var inputAlphabet = Enumerable.Range(0, 256 + intCast.Count);
			input = intCast.SelectMany((d, i) => d.Concat(new[] { 256 + i })).ToList();

			Func<int, bool> isNotAlphabetSymbol = c => c.CompareTo(256) >= 0;
			tree = new SuffixTree<int>(input, inputAlphabet, isNotAlphabetSymbol, documentsInfo);
		}

		public List<DocumentOccurrences> ReportOccurrences(byte[] pattern)
		{
			var w = pattern.Select(x => (int)x).ToList();
			
			if (!tree.TryGetSubtree(
				w, out SuffixTree<int>.Node? subtree, out int pathLengthToReachSubtree)) {
				return new List<DocumentOccurrences>();
			}

			var occurences = subtree.Traverse(pathLengthToReachSubtree)
				.Select(n => new {
					DocumentKey = n.DocumentInfo.Key, 
					Position = input.Count - n.PathLengthToReach - n.DocumentInfo.StartPositionInInput})
				.OrderBy(t => t.DocumentKey).ToList();

			var result = new List<DocumentOccurrences>();
			if (occurences.Count == 0) return result;

			var documentOccurences = new DocumentOccurrences() { 
				DocumentKey = occurences.First().DocumentKey,
				OccurrencePositions = new List<int>() { occurences.First().Position }
			};

			foreach (var occurence in occurences.Skip(1)) {
				if (occurence.DocumentKey != documentOccurences.DocumentKey) {
					result.Add(documentOccurences);
					documentOccurences = new DocumentOccurrences() {
						DocumentKey = occurence.DocumentKey,
						OccurrencePositions = new List<int>()
					};
				}
				documentOccurences.OccurrencePositions.Add(occurence.Position);
			}

			result.Add(documentOccurences);
			return result;
		}
	}
}