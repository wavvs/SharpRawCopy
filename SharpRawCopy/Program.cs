using System.Linq;
using System.Runtime.InteropServices;

namespace SharpRawCopy
{
    public class Program
    {
        // TODO:
        // 1. Compress resource
        // 2. Hide imports (DInvoke)
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void Copy(int argc, string[] argv);
        static void Main(string[] args)
        {
            DLLFromMemory dLLFromMemory = new DLLFromMemory(Resource1.rawccopy_x64);
            Copy copyFunc = dLLFromMemory.GetDelegateFromFuncName<Copy>("Copy");
            var argsList = args.ToList();
            argsList.Insert(0, "");
            copyFunc(argsList.Count, argsList.ToArray());
            dLLFromMemory.Close();
        }
    }
}
