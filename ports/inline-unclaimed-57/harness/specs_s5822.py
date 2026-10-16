"""specs_s5822.py - unclaimed-57, batch 122: 0x5db420 (ZDamageBox::Load(ZLoadGame*), thiscall, one stack arg, ret 4, returns al = 1). The load object L has a fake
vtable: slot +0x40 (one arg: writes the next value of a per-case list through the pointer: first the value for l1, then the count 0 to 3 (the loop bound),
then a dword per iteration), +0x50 (one arg: writes a fixed dword through the pointer). The engine sub-object (+0x9b) has slot +0x58 (one arg, logged; returns
an object O with slot +0x1e0 (one arg, logged; returns a per-call flag)). this+0x84 is an object M with slot +4 (one arg, logged). The allocator 0x41e290 (cdecl)
returns a 13-byte allocation. Pointers into this and the allocation are logged as offsets, never addresses."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d5420(c):
    e = c.emu
    cnt = c.rng.randrange(0, 4)
    seq40 = [c.rng.getrandbits(32), cnt] + [c.rng.getrandbits(32) for _ in range(4)]
    i40 = [0]
    w50 = c.rng.getrandbits(32)
    flags = [c.rng.choice([0, 1]) for _ in range(4)]
    f_i = [0]
    rv58 = c.rng.getrandbits(32)
    self_obj = _rnd(c, 0x100)
    blocks = {}

    def rel(p):
        if self_obj <= p < self_obj + 0x100:
            return ('self', p - self_obj)
        for k, b in blocks.items():
            if b <= p < b + 0x40:
                return ('alloc', k, p - b)
        return ('other',)

    def hL40(em, r):
        p = em.arg32(0)
        k = i40[0]
        i40[0] += 1
        em.calllog.append(('L40', k, None, (rel(p),)))
        em.w32(p, seq40[k] if k < len(seq40) else 0)
        em.ret(eax=0, argbytes=4)

    def hL50(em, r):
        p = em.arg32(0)
        em.calllog.append(('L50', 0, None, (rel(p),)))
        em.w32(p, w50)
        em.ret(eax=0, argbytes=4)

    def halloc(em, r):
        size = em.arg32(0)
        em.calllog.append(('41e290', 0, None, (size,)))
        p = em.alloc(max(size, 4), 4)
        blocks[len(blocks)] = p
        em.ret(eax=p, argbytes=0)

    def h58(em, r):
        em.calllog.append(('s58', 0, None, (em.arg32(0),)))
        em.ret(eax=O_obj, argbytes=4)

    def h1e0(em, r):
        k = f_i[0]
        f_i[0] += 1
        em.calllog.append(('O1e0', 0, None, (em.arg32(0),)))
        em.ret(eax=flags[k % 4], argbytes=4)

    def hM4(em, r):
        em.calllog.append(('M4', 0, None, (rel(em.arg32(0)),)))
        em.ret(eax=0, argbytes=4)

    e.hook(0x41e290, halloc)
    vt_L = e.fake_vtable('d5420_L', 200, {0x40: hL40, 0x50: hL50})
    vt_sub = e.fake_vtable('d5420_sub', 200, {0x58: h58})
    vt_O = e.fake_vtable('d5420_O', 600, {0x1e0: h1e0})
    vt_M = e.fake_vtable('d5420_M', 200, {4: hM4})
    O_obj = _rnd(c, 0x40)
    e.w32(O_obj, vt_O)
    M = _rnd(c, 0x40)
    e.w32(M, vt_M)
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    e.w32(self_obj + 0x84, M)
    L = _rnd(c, 0x40)
    e.w32(L, vt_L)
    return [self_obj, L]


S(0x5db420, 'ZDamageBox::Load (GUESS) thiscall', 'thiscall', None, ret='al', gen=_d5420,
  note='unclaimed-57 batch 122; L slots +0x40 and +0x50 fake (count from the argument slot); engine sub slot +0x58; O slot +0x1e0; M slot +4; 0x41e290 hooked')
