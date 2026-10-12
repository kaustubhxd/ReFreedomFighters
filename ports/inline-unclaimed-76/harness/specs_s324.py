"""specs_s324.py - gap band, batch 324: three scalar deleting destructors (thiscall, one stack argument: the flags).
The base destructors run as exe code on a random object; the CRT free wrapper 0x634273 is hooked (recorded, returns 0). The base
destructors may use the engine global 0x70039c; a random 0x2000-byte engine block is installed for them."""
from pilot import S


def _rec(em, r):
    # 0x634273 (cdecl, two arguments): free wrapper, recorded
    em.calllog.append(('free634273', 0, None, (em.arg32(0), em.arg32(1))))
    em.ret(eax=0, argbytes=0)


def _base(addr):
    def h(em, r):
        # a base destructor (thiscall, no arguments; SEH frame not modelled): recorded by address, returns
        em.calllog.append(('base', addr, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)
    return h


def _gen(size):
    def gen(c):
        e = c.emu
        rng = c.rng
        e.hook(0x634273, _rec)
        for a in (0x601020, 0x608080, 0x63ab30):
            e.hook(a, _base(a))
        e.stub_import('malloc', lambda em, rr: em.ret(eax=em.alloc(max(em.arg32(0), 4), 16), argbytes=0))
        e.stub_import('free', lambda em, rr: em.ret(eax=0, argbytes=0))
        e.stub_import('memset', lambda em, rr: (em.mu.mem_write(em.arg32(0), bytes([em.arg32(1) & 0xff]) * em.arg32(2)) if em.arg32(2) else None, em.ret(eax=em.arg32(0), argbytes=0))[1])
        eng = e.alloc(0x2000, 4)
        e.wbytes(eng, bytes(rng.getrandbits(8) for _ in range(0x2000)))
        e.w32(0x70039c, eng)
        obj = e.alloc(size + 0x10, 4)
        e.wbytes(obj, bytes(rng.getrandbits(8) for _ in range(size + 0x10)))
        return [obj, rng.getrandbits(32)]
    return gen


S(0x601440, 'sdtor601440 (GUESS)', 'thiscall', None, ret='eax', gen=_gen(0x40), note='batch324; ret 4; free 0x634273 and base dtor hooked')
S(0x6081f0, 'sdtor6081f0 (GUESS)', 'thiscall', None, ret='eax', gen=_gen(0x1800), note='batch324; ret 4; free 0x634273 and base dtor hooked')
S(0x613950, 'sdtor613950 (GUESS)', 'thiscall', None, ret='eax', gen=_gen(0xba00), note='batch324; ret 4; free 0x634273 and base dtor hooked')
