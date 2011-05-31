using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace LinearComplexity
{
    class Program
    {

        // Implementation of Berlekamp-Massey algorithm for calculating linear 
        // complexity of binary sequence
        // s = byte array with binary sequence
        // returns Length of LFSR with smallest length which generates s
        // for an example: int L=BerlekampMassey(new byte[] {1,0,1,0,1,1,1,0,1,0})
        //        reference: "Handbook of Applied Cryptography", p201

        public static byte[] BerlekampMassey(byte[] s, ref int l)
        {
            int L, N, m, d;
            int n = s.Length;
            byte[] c = new byte[n];
            byte[] b = new byte[n];
            byte[] t = new byte[n];

            //Initialization
            b[0] = c[0] = 1;
            N = L = 0;
            m = -1;

            //Algorithm core
            while (N < n)
            {
                d = s[N];
                for (int i = 1; i <= L; i++)
                    d ^= c[i] & s[N - i];            //(d+=c[i]*s[N-i] mod 2)
                if (d == 1)
                {
                    Array.Copy(c, t, n);    //T(D)<-C(D)
                    for (int i = 0; (i + N - m) < n; i++)
                        c[i + N - m] ^= b[i];
                    if (L <= (N >> 1))
                    {
                        L = N + 1 - L;
                        m = N;
                        Array.Copy(t, b, n);    //B(D)<-T(D)
                    }
                }
                N++;
            }
            
            l = L;
            return c;
        }

        static void Main(string[] args)
        {
            int l1 = 0, l2 = 0;
            byte[] a = BerlekampMassey(new byte[] { 0, 0, 1, 1, 0, 1, 1, 1, 0 }, ref l1);
            byte[] a1 = BerlekampMassey(new byte[] { 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0 }, ref l1);
            byte[] a2 = BerlekampMassey(new byte[] { 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 }, ref l2);
            //int L = BerlekampMassey(new byte[] { 7, 0, 3, 100, 7, 0, 3, 100, 7, 0, 3, 100, 7, 0, 3, 100, 7, 0, 3, 100, 7, 0, 3, 100 });
            //System.Console.WriteLine(L);

            String str = BitConverter.ToString(a);
            System.Console.WriteLine(str);

            String str1 = BitConverter.ToString(a1);
            System.Console.WriteLine(l1);
            System.Console.WriteLine(str1);

            String str2 = BitConverter.ToString(a2);
            System.Console.WriteLine(l2);
            System.Console.WriteLine(str2);
        }
    }
}
