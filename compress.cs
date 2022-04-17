using System;
using System.Collections.Generic;
using System.Linq;

namespace task_compress
{
	class ListComparer : IComparer<List<byte>>
    {
        public int Compare(List<byte> lhs, List<byte> rhs)
        {
            for (var i = 0; i < Math.Min(lhs.Count, rhs.Count); i++)
            {
                var cmp = lhs[i].CompareTo(rhs[i]);
                if (cmp != 0) return cmp;
            }

            return lhs.Count.CompareTo(rhs.Count);
        }
    }
    
	class Compressor
	{
		public const int ALPH_SIZE = 256;
		
		public static int[] DataToIds(byte[] data)
		{
			var dict = new SortedDictionary<List<byte>, int>(new ListComparer());
			for (int i = 0; i < ALPH_SIZE; i++) {
				dict[new List<byte>() {(byte)i}] = i;
			}
			
			var output = new List<int>();
			var w = new List<byte>();
			
			foreach (var a in data) {
				var wa = new List<byte>(w) {a};
				
				if (dict.ContainsKey(wa)) {
					w = wa;
				} else {
					output.Add(dict[w]);
					dict.Add(wa, dict.Count);
					
					w = new List<byte>() {a};
				}
			}
			
			if (w.Count != 0) {
				output.Add(dict[w]);
			}
			
			return output.ToArray();
		}
		
		public static byte[] IdsToData(int[] ids)
		{
			var dict = new Dictionary<int, List<byte>>();
            for (int i = 0; i < ALPH_SIZE; i++) {
                dict.Add(i, new List<byte> {(byte)i});
            }

            var prev = new List<byte>();
            var output = new List<byte>();

            foreach (var i in ids) {
                var chunk = new List<byte>();
                if (dict.ContainsKey(i)) {
                	chunk.AddRange(dict[i]);
                } else {
                    chunk.AddRange(prev);
                    chunk.Add(prev[0]);
                }

                output.AddRange(chunk);

                prev.Add(chunk[0]);
                if (prev.Count > 1) {
                	dict.Add(dict.Count, new List<byte>(prev));
                }

                prev = chunk;
            }

            return output.ToArray();
		}
		
		public static byte[] Compress(byte[] data)
		{
			var ids = DataToIds(data);
			var output = new List<byte>();
			int id_bits = 8, curr_bit = 0;
			for (int id = 0; id < ids.Length; id++)
			{
				int new_size = (curr_bit + id_bits + 7) / 8 + 8;
				output.AddRange(new byte[new_size - output.Count]);
				var bytes = BitConverter.GetBytes((ulong)ids[id] << curr_bit % 8);
				for (int k = 0; k < 2 + id_bits/8; k++)
					output[curr_bit/8 + k] |= bytes[k];
				curr_bit += id_bits;
				if (256 + id >= (1 << id_bits))
					id_bits++;
			}
			output.RemoveRange((curr_bit + 7) / 8, 8);
			return output.ToArray();
		}
		
		public static byte[] Decompress(byte[] data)
		{
			var ids = new List<int>();
			int id_bits = 8, curr_bit = 0, last_bit = data.Length * 8;
			data = data.Concat(new byte[8]).ToArray();
			for (int id = 0; curr_bit + id_bits <= last_bit; id++)
			{
				ulong x = BitConverter.ToUInt64(data, curr_bit / 8);
				ids.Add((int)(x >> curr_bit % 8) & (1 << id_bits) - 1);
				curr_bit += id_bits;
				if (256 + id >= (1 << id_bits))
					id_bits++;
			}
			return IdsToData(ids.ToArray());
		}
	}
}
