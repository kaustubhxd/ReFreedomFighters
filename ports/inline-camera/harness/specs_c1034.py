"""specs_c1034.py - camera batch 1034: ZCamHelper::ZCamHelper. The exe calls it makes are hooked (both builds see the
same hooks). _stricmp is stubbed (case-insensitive compare, cdecl). Options come from a fake sys object."""
from pilot import S
from camgen import rnd, Log, handler, sys_with_mgr


def _ctor(c):
    r = c.rng
    log = Log(c, 512)
    for a in (0x469870, 0x662750, 0x662be0, 0x662ed0):
        c.emu.hook(a, handler(log, a, 0, eax=0))

    def coli(e, res):  # COLI::COLI(this): logs the tag only
        log.put(0x4e1b60)
        e.ret(eax=e.reg('ecx'), argbytes=0)
    c.emu.hook(0x4e1b60, coli)

    def mreset(e, res):  # mreset gets a stack-frame address in ECX: log the tag only
        log.put(0x4de7a0)
        e.ret(argbytes=0)
    c.emu.hook(0x4de7a0, mreset)

    def opnew(e, res):  # cdecl operator new(size): the caller pops; returns a heap block
        log.put(0x41e290, e.arg32(0))
        p = c.emu.alloc(max(e.arg32(0), 16), 16)
        e.ret(eax=p, argbytes=0)
    c.emu.hook(0x41e290, opnew)

    def autoaim(e, res):  # option object ctor (this, name, desc, float* out): writes a float default
        log.put(0x4d8330, e.arg32(0), e.arg32(1), e.arg32(2))
        pass
        e.ret(eax=r.getrandbits(32), argbytes=12)
    c.emu.hook(0x4d8330, autoaim)

    values = {}
    def read_val(e, res):  # sys slot 0x5c(name, out*): writes a pointer to a heap string; returns found
        name = e.arg32(0)
        out = e.arg32(1)
        choice = r.choice(['A', 'a', 'B', 'off', ''])
        buf = c.emu.alloc(16, 4)
        c.emu.wbytes(buf, choice.encode('latin-1') + b'\0')
        e.w32(out, buf)
        log.put(0x5c, name)
        e.ret(eax=r.choice([0, 1]), argbytes=8)

    def mgr_ref(e, res):  # mgr slot 0x114(name, 0, file, line) -> handle word
        log.put(0x114, e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3))
        e.ret(eax=r.getrandbits(16), argbytes=16)
    s = sys_with_mgr(c, 0x1d00)
    vt = c.emu.fake_vtable('sys', 0x1c0 // 4, {0x5c: read_val,
                                             0x1a4: handler(log, 0x1a4, 1, eax=0)})
    c.emu.w32(s, vt)
    m = c.emu.fake_object('mgr', 0x140, slots={0x114: mgr_ref})
    c.emu.w32(s + 0x9b, m)

    def stricmp(e, res):  # cdecl _stricmp(a, b): the caller pops; case-insensitive compare of two C strings
        def cs(addr):
            out = b''
            for i in range(64):
                ch = e.r8(addr + i)
                if ch == 0:
                    break
                out += bytes([ch])
            return out.lower()
        a, b = cs(e.arg32(0)), cs(e.arg32(1))
        v = (a > b) - (a < b)
        e.ret(eax=v & 0xffffffff, argbytes=0)
    c.emu.stub_import('_stricmp', stricmp)

    self_ = rnd(c, 0xf00)
    return [self_]


S(0x5cce70, 'ZCamHelper::ZCamHelper', 'thiscall', gen=_ctor)
