"""specs_s272.py - area 22, batch272 (src/batch272.cpp): ZActor::ZActor. The base constructor 0x471b50 (verified in
audit/inline-ladder) is hooked so this spec does not need its whole tree; MYSTR::MYSTR 0x4cbeb0 and the debug variable
constructor 0x4d8330 are not verified anywhere and are hooked as GUESS stubs (all logged, return ecx). The allocator
0x41e290 (unclaimed-64) runs as exe code over a Python allocator at [0x70038c] (slot 8, per-case blocks or 0); the table
constructor 0x4ccbe0 (inline-batch45) and the CRT memset thunk 0x634d10 run as exe code (memset import stubbed in Python, cdecl). Engine db vt[0x114] returns a
per-call random word; rm vt[0x1a4] is logged. The actor counter 0x6ffa4c is set per case (0..8)."""
from pilot import S
from helpers22 import _rnd, _multi_vt, _hk


def _memset(em, r):
    d, v, n = em.arg32(0), em.arg32(1), em.arg32(2)
    em.wbytes(d, bytes([v & 0xff]) * n)
    em.ret(eax=d, argbytes=0)


def _g_476f50(c):
    e = c.emu
    e.stub_import('memset', _memset)
    db = _rnd(c, 0x100)
    e.w32(db, _multi_vt(c, {0x114: (lambda em, a: (c.rng.getrandbits(32), None), 4)}))
    rm = _rnd(c, 0x100)
    e.w32(rm, _multi_vt(c, {0x1a4: (lambda em, a: (0, None), 1)}))
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    blocks = [c.rng.choice([_rnd(c, sz), _rnd(c, sz), _rnd(c, sz), 0]) for sz in (0x1c, 0x108, 0x108)]
    seq = list(blocks)
    al = _rnd(c, 0x10)
    e.w32(al, _multi_vt(c, {8: (lambda em, a: (seq.pop(0) if seq else 0, None), 1)}))
    e.w32(0x70038c, al)
    lst = _rnd(c, 8 + 4 * 40)
    e.w32(lst + 4, c.rng.randrange(0, 39))
    e.w32(0x7003b8, lst)
    e.w32(0x6ffa4c, c.rng.choice([0, 1, 6, 7, 7, 8, c.rng.randrange(0, 8)]))
    e.w32(0x6ffa10, c.rng.getrandbits(32))
    e.wbytes(0x6ffa1c, bytes(c.rng.getrandbits(8) for _ in range(0x2c)))
    _hk(c, 0x471b50, 'base.471b50', 3, eax=lambda em: em.reg('ecx'))
    _hk(c, 0x4cbeb0, 'mystr.4cbeb0', 0, eax=lambda em: em.reg('ecx'))
    _hk(c, 0x4d8330, 'dbgvar.4d8330', 3, eax=lambda em: em.reg('ecx'))
    e.mu.ctl_flush_tb()
    return [_rnd(c, 0x800), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x476f50, 'ZActor::ZActor', 'thiscall', None, ret='eax', gen=_g_476f50,
  note='batch272; base ctor 0x471b50 hooked (verified elsewhere), MYSTR ctor 0x4cbeb0 and debug variable ctor 0x4d8330 hooked (GUESS); allocator, table ctor, memset as exe code; SEH frame and cookie not reproduced')
