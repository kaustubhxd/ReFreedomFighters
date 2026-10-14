"""specs_s908.py - gap-band slice, batch 908: 0x41dd90 (GUESS name Load41dd90), cdecl-style, no args, returns al (bool).
Stand-ins (KERNEL32 imports, stub_import): LoadLibraryA (returns a drawn handle or 0), GetProcAddress (returns a fresh stub address per
name, or 0 for one drawn name; logs the name), GetCurrentProcess (returns a value), GetModuleFileNameA (writes a path into the buffer,
or returns 0), GetCurrentDirectoryA (writes "C:\\game\\x" tail and returns its length, or 0), GetEnvironmentVariableA (returns a length or
0), FreeLibrary (logs). The function-pointer globals 0x6fcd68/0x6fcd74/0x6fcd70 are the GetProcAddress stubs (they log their arguments).
Real exe code: 0x41d500 (path helper). The stack cookie check is not reproduced (noted in the doc).
The globals 0x6fcd7c (counter), 0x6fcd80, 0x6fcd78 and 0x6e4084 (record pointer) are set per case."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    lib = r.choice([0x1234, 0x5678, 0])
    fail_at = r.choice([None, None, None, 0, 3, 9, 10])
    gpa_count = [0]
    fn_addrs = {}

    arity = {'SymGetOptions': 0, 'SymSetOptions': 1, 'SymInitialize': 3}

    def mk_fn(name):
        n = arity.get(name, 0)
        def h(e, rr):
            words = []
            for k in range(n):
                v = e.arg32(k)
                if name == 'SymInitialize' and k == 1:
                    words.append(e.rbytes(v, 40).split(b'\0')[0])   # a search path in the stack buffer: log its text, not its address
                else:
                    words.append(v)
            e.calllog.append(('fn.' + name,) + tuple(words))
            e.ret(eax=0, argbytes=4 * n)      # stdcall: the callee pops its arguments
        return h

    def gpa(e, rr):
        mod, name = e.arg32(0), e.arg32(1)
        k = gpa_count[0]
        gpa_count[0] += 1
        txt = e.rbytes(name, 40).split(b'\0')[0]
        e.calllog.append(('GetProcAddress', mod, txt))
        if fail_at is not None and k == fail_at:
            e.ret(eax=0, argbytes=8)
            return
        e.ret(eax=fn_addrs.setdefault(txt, e.stub_fn(txt.decode('latin-1'), mk_fn(txt.decode('latin-1')))), argbytes=8)

    def load(e, rr):
        e.calllog.append(('LoadLibraryA', e.rbytes(e.arg32(0), 20).split(b'\0')[0]))
        e.ret(eax=lib, argbytes=4)

    def getcp(e, rr):
        e.calllog.append(('GetCurrentProcess',))
        e.ret(eax=0xfffffffe, argbytes=0)

    path = b'C:\\game\\files\\ff.exe'
    ncase = r.random() < 0.6

    def gmfn(e, rr):
        buf, size = e.arg32(1), e.arg32(2)
        e.calllog.append(('GetModuleFileNameA', e.arg32(0), size))
        if not ncase:
            e.ret(eax=0, argbytes=12)
            return
        e.wbytes(buf, path + b'\0')
        e.ret(eax=len(path), argbytes=12)

    def gcd(e, rr):
        size, buf = e.arg32(0), e.arg32(1)
        e.calllog.append(('GetCurrentDirectoryA', size > 0x800, buf != 0))
        e.wbytes(buf, b'mod\0')
        e.ret(eax=3, argbytes=8)

    def genv(e, rr):
        nm = e.rbytes(e.arg32(0), 20).split(b'\0')[0]
        e.calllog.append(('GetEnvironmentVariableA', nm, e.arg32(1) != 0))
        e.ret(eax=r.choice([0, 2, 5]), argbytes=12)

    def flib(e, rr):
        e.calllog.append(('FreeLibrary', e.arg32(0)))
        e.ret(eax=1, argbytes=4)

    e.stub_import('LoadLibraryA', load)
    e.stub_import('GetProcAddress', gpa)
    e.stub_import('GetCurrentProcess', getcp)
    e.stub_import('GetModuleFileNameA', gmfn)
    e.stub_import('GetCurrentDirectoryA', gcd)
    e.stub_import('GetEnvironmentVariableA', genv)
    e.stub_import('FreeLibrary', flib)
    e.w32(0x6fcd7c, 0 if r.random() < 0.7 else 1)
    e.w32(0x6e4084, rnd(c, 0x40))
    return []


S(0x41dd90, 'Load41dd90 (GUESS name; cookie not reproduced)', 'cdecl', None, ret='al', gen=_gen, note='area50 batch908 (band slice)')
