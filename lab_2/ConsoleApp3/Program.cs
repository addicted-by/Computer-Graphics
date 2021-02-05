using System;

namespace Lab_2
{
    class A
    {
        public A() { }


        public void mA() { Console.WriteLine("method of A"); }


        public B bA
        {
            set { Console.WriteLine("set b"); b = value; }
            get { Console.Write("get b ->"); return b; }
        }
        public C cA
        {
            set { Console.WriteLine("set c"); c = value; }
            get { Console.Write("get c ->"); return c; }
        }
        private B b = new B();
        private C c = new C();
    }
    class B
    {

        public B() { }

        public void mB() { Console.WriteLine("method of B"); }

        public D dA
        {
            set { Console.WriteLine("set d"); d = value; }
            get { Console.Write("get d -> "); return d; }
        }
        private D d = new D();

    }

    class C
    {
        public C() { }


        public void mC() { Console.WriteLine("method of C"); }

        public E eA
        {
            set { Console.WriteLine("set e"); e = value; }
            get { Console.Write("get e ->"); return e; }
        }

        public F fA
        {
            set { Console.WriteLine("set f"); f = value; }
            get { Console.Write("get f ->"); return f; }
        }
        private E e = new E();
        private F f = new F();
    }
    class D
    {
        public D() { }

        public void mD() { Console.WriteLine(" method of D"); }
    }

    class E
    {
        public E() { }

        public void mE() { Console.WriteLine(" method of E"); }
    }

    class F
    {
        public F() { }

        public void mF() { Console.WriteLine(" method of F"); }
    }

    class Program
    {
        static void Main(string[] args)
        {
            A a = new A();
            a.mA();
            a.bA.mB();
            a.cA.mC();

            a.bA.dA.mD();

            a.cA.eA.mE();
            a.cA.fA.mF();
            Console.ReadKey();
        }
    }
}
