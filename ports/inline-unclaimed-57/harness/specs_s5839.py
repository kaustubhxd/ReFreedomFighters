"""specs_s5839.py - residue 9, 0x5db910 (ZDamageBox2::CopyData(ZEventBase*), gc name map), thiscall, one stack argument (src), ret 4. src+0x48 (s48, non-null in
about 85% of the cases) has slot +0x4c (writes a per-case dword v through the pointer) and slot +0x5c (writes the next value of a short list through the pointer, the
list ends with 0; returns a per-case dword r). this+0x48 is always an object with slot +4 (logs the argument). The copied fields are random; the field +0x4c is
0, 1 or random so both branches run."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d5910(c):
    e = c.emu
    rnd = c.rng
    v4c = rnd.choice([0, 1, rnd.getrandbits(32)])
    seq = [rnd.getrandbits(32) for _ in range(rnd.randrange(0, 4))] + [0]
    k5c = [0]
    r5c = rnd.getrandbits(32)

    def hs4c(em, r):
        em.calllog.append(('s4c', 0, None, ()))
        em.w32(em.arg32(0), v4c)
        em.ret(eax=0, argbytes=4)

    def hs5c(em, r):
        i = k5c[0]
        k5c[0] += 1
        em.calllog.append(('s5c', i, None, ()))
        em.w32(em.arg32(0), seq[i] if i < len(seq) else 0)
        em.ret(eax=r5c, argbytes=4)

    def hd4(em, r):
        em.calllog.append(('d4', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    vt_s = e.fake_vtable('d5910_s48', 200, {0x4c: hs4c, 0x5c: hs5c})
    vt_d = e.fake_vtable('d5910_d48', 200, {0x4: hd4})
    src_s48 = _rnd(c, 0x40)
    e.w32(src_s48, vt_s)
    dst_s48 = _rnd(c, 0x40)
    e.w32(dst_s48, vt_d)
    src = _rnd(c, 0x100)
    if rnd.random() < 0.85:
        e.w32(src + 0x48, src_s48)
    else:
        e.w32(src + 0x48, 0)
    e.w32(src + 0x4c, rnd.choice([0, 1, rnd.getrandbits(32)]))  # the copied counter: both branches run
    self_obj = _rnd(c, 0x100)
    e.w32(self_obj + 0x48, dst_s48)
    return [self_obj, src]


S(0x5db910, 'ZDamageBox2::CopyData (gc map) thiscall', 'thiscall', None, ret=None, gen=_d5910,
  note='residue 9; src+0x48 fake (slots +0x4c and +0x5c logged); this+0x48 fake (slot +4 logged)')
