using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PolindromeKvadrat
{
    //public class MatrixPoint
    //{
    //    public int X;
    //    public int Y;
    //}

    public class MatrixPoint
    {
        public int X;
        public int Y;
    }


    public class PolindromeDetector
    {
        private class Node
        {
            public Node(int horizontalPolindromeLen, int verticalPolindromeLen)
            {
                HorizontalPolindromeLen = horizontalPolindromeLen;
                VerticalPolindromeLen = verticalPolindromeLen;
            }

            public int HorizontalPolindromeLen;
            public int VerticalPolindromeLen;
        }        
        
        private Node[,] _matrix;
        
        public ICollection<MatrixPoint> GetBiggestSquare(ICollection<string> inputStrings)
        {
            _matrix = new Node[inputStrings.First().Length, inputStrings.Count];
            
            List<MatrixPoint> result = new List<MatrixPoint>();

            FindAllHorizontalPolindromes(inputStrings);

            return result;
        }


        private void FindAllHorizontalPolindromes(ICollection<string> inputStrings)
        {
            foreach (string inputString in inputStrings)
            {
                Dictionary<int, int> polindromesInString = FindPolindrome(inputString);
                foreach (KeyValuePair<int, int> poli in polindromesInString)
                {
                    int poliLen = poli.Value - poli.Key;
                    if (poliLen > 0)
                        _matrix[poli.Key, poli.Value] = new Node(poliLen, 0);
                }
            }
        }

        private Dictionary<int, int> FindPolindrome(string inputString)
        {
            Dictionary<int, int> result = new Dictionary<int, int>();

            for (int character = 0; character < inputString.Length; ++character)
            {
                int leftI = character;
                int rightI = inputString.Length - 1;
                int begin = character;
                int end = begin;
                //for (int leftI = character; leftI < inputString.Length; ++leftI)
                while (leftI < rightI)
                {
                    if (leftI + 1 == rightI && inputString[leftI] == inputString[rightI])
                    {
                        result.Add(begin, end);
                        break;
                    }

                    if (inputString[leftI] == inputString[rightI])
                    {
                        if(end == begin)
                            end = rightI;
                        --rightI;
                        ++leftI;
                    }
                    else 
                    {
                        leftI = character;
                        //if (end == begin)
                            --rightI; // first fail - move right
                        end = begin;
                    }

                }
            }
            return result;
        }

    }

}
