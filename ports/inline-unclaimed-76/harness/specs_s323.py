"""specs_s323.py - gap band, batch 323: setIndexed (604430) and a constructor (613900).
604430: the global 0x724278 points to a fake block whose +0x3c is an object; its vtable slot 0 is a thiscall stub (one argument) that
returns a small index (0..15) and logs its argument. this+8 points to a 64-byte table. 613900: the base constructor 0x65a380 runs as exe
code on a 0xb9b8-byte object (random bytes)."""
from pilot import S


def _setidx(c):
    e = c.emu
    rng = c.rng
    idx = rng.choice([rng.randrange(0, 16), 0x100 + rng.randrange(0, 16)])   # some indices above 255: the port keeps the 16-bit index

    def slot0(em, r):
        a = em.arg32(0)
        em.calllog.append(('slot0_323', 0, em.reg('ecx'), (a,)))
        em.ret(eax=idx, argbytes=4)

    obj = e.alloc(0x40, 4)
    e.w32(obj, e.fake_vtable('obj323', 0x20, {0: slot0}))
    g = e.alloc(0x80, 4)
    e.wbytes(g, bytes(rng.getrandbits(8) for _ in range(0x80)))
    e.w32(g + 0x3c, obj)
    e.w32(0x724278, g)
    self_ = e.alloc(0x40, 4)
    e.wbytes(self_, bytes(rng.getrandbits(8) for _ in range(0x40)))
    table = e.alloc(0x40, 4)
    e.wbytes(table, bytes(rng.getrandbits(8) for _ in range(0x40)))
    e.w32(self_ + 8, table)
    return [self_, rng.getrandbits(32), rng.getrandbits(32)]


def _memset(em, r):
    # cdecl import VCRUNTIME140.memset(dst, value, n): the caller pops the arguments
    dst, val, n = em.arg32(0), em.arg32(1) & 0xff, em.arg32(2)
    if n:
        em.mu.mem_write(dst, bytes([val]) * n)
    em.ret(eax=dst, argbytes=0)


def _ctor(c):
    e = c.emu
    # CRT malloc (cdecl) through its import; the engine global must have a readable block (0x190f is read by the base ctor)
    e.stub_import('malloc', lambda em, rr: em.ret(eax=em.alloc(max(em.arg32(0), 4), 16), argbytes=0))
    e.stub_import('free', lambda em, rr: em.ret(eax=0, argbytes=0))
    e.stub_import('memset', _memset)
    eng = e.alloc(0x2000, 4)
    e.wbytes(eng, bytes(c.rng.getrandbits(8) for _ in range(0x2000)))
    e.w32(0x70039c, eng)
    obj = e.alloc(0xb9b8, 4)
    e.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0xb9b8)))
    return [obj]


S(0x604430, 'setIndexed604430 (GUESS)', 'thiscall', None, ret=None, gen=_setidx, note='batch323; ret 8; slot 0 stubbed')
S(0x613900, 'ctor613900 (GUESS)', 'thiscall', None, ret='eax', gen=_ctor, note='batch323; base ctor 0x65a380 runs as exe code')
