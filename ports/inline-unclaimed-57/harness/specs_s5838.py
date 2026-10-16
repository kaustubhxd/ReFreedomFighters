"""specs_s5838.py - residue 9, 0x592350 (ZFFHERO::GetSpawnpointListFromTeam(int), gc name map), stdcall, one stack argument (team), ret 4. The sub-object (engine +0x9b)
has slot +0x138 (no args, returns object O). O has slot +0x88 (two args: the key and a pointer; logs the key and writes a per-key dword through the pointer). The
team argument is mostly in 3..6 (the four keys), sometimes outside (the default returns 0)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d2350(c):
    e = c.emu
    rnd = c.rng
    vals = {k: rnd.getrandbits(32) for k in (0x6acfcc, 0x6acfdc, 0x6acfec, 0x6acffc)}
    do_write = rnd.random() < 0.7

    def h138(em, r):
        em.calllog.append(('138', 0, None, ()))
        em.ret(eax=O_obj, argbytes=0)

    def h88(em, r):
        k = em.arg32(0)
        em.calllog.append(('88', k, None, ()))
        if do_write:
            em.w32(em.arg32(1), vals.get(k, 0))  # otherwise the caller's initial value is returned
        em.ret(eax=0, argbytes=8)

    vt_sub = e.fake_vtable('d2350_sub', 200, {0x138: h138})
    vt_O = e.fake_vtable('d2350_O', 300, {0x88: h88})
    O_obj = _rnd(c, 0x40)
    e.w32(O_obj, vt_O)
    sub = _rnd(c, 0x100)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    team = rnd.choice([3, 4, 5, 6]) if rnd.random() < 0.85 else rnd.choice([0, 1, 2, 7, 8, 0x80000000, 0xffffffff])
    return [team]


S(0x592350, 'ZFFHERO::GetSpawnpointListFromTeam (gc map) stdcall', 'stdcall', None, ret='eax', gen=_d2350,
  note='residue 9; sub slot +0x138 fake; O slot +0x88 fake (key logged, per-key dword written)')
