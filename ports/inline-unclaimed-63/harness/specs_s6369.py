"""specs_s6369.py - unclaimed-63 batch 69: 0x4a2ba0 (ZParamAnim::Save, GUESS name; thiscall, one stack argument s, ret 4, returns true).
Fakes per case (the image is restored between runs):
  * s: one vtable with slots +0x60, +0x40, +0x54, +0x4c (each thiscall, one argument, ret 4) that record ECX and their argument (the float
    slots record the bits);
  * the embedded object at this+0x59: its first dword is a vtable whose slot +0x18 (thiscall, one argument, ret 4) records ECX and the
    argument;
  * this: random bytes (so the byte, word, dword and float fields vary, NaN included)."""
from pilot import S


def _gen_4ba0(c):
    e = c.emu
    this = e.alloc(0x140, 4)
    e.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x140)))
    def rec(name, off):
        def h(em, a):
            em.calllog.append((name, off, em.reg('ecx'), (em.arg32(0),)))
            em.ret(eax=0, argbytes=4)
        return h
    s = e.alloc(0x40, 4)
    e.wbytes(s, bytes(0x40))
    e.w32(s, e.fake_vtable('s', 0x400 // 4, {0x60: rec('s.60', 0x60), 0x40: rec('s.40', 0x40), 0x54: rec('s.54', 0x54), 0x4c: rec('s.4c', 0x4c)}))
    V = e.fake_vtable('emb', 0x400 // 4, {0x18: rec('emb.18', 0x18)})
    e.w32(this + 0x59, V)
    e.mu.ctl_flush_tb()
    return [this, s]


S(0x4a2ba0, 'ZParamAnim::Save thiscall (GUESS name)', 'thiscall', None, ret='al', gen=_gen_4ba0,
  note='unclaimed-63 batch 69')
