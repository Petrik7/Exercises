using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PolindromeKvadrat
{
    class FileLinesReader
    {
        public static ICollection<string> GetLines(string fileName)
        {
            List<string> result = new List<string>();

            try
            {
                string line;
                StreamReader inputDataFile = new StreamReader(fileName);
                while ((line = inputDataFile.ReadLine()) != null)
                {
                    result.Add(line);
                }
            }
            catch(System.IO.IOException )
            {
                // Handle exception
            }

            return result;
        }
    }
}
