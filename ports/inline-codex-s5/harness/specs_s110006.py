"""specs_s5814.py - unclaimed-57, batch 114: 0x5d8d60 (GUESS name unnamed_5d8d60). Thiscall, four stack arguments (ret 0x10). The array at this+0x20 is
null in about one case in five (early path: 0x45dc90 is hooked as a logging stub, stdcall, four args). Otherwise the divisors this+0x30 and this+0x40 are
nonzero (in 1..9 with random sign), N1 (this+0x18) is 0 to 3 and N2 (this+0x1c) is 0 to 2. The engine (global 0x70039c) has its own fake vtable with slot
+0x1bc (two args: a dword that is returned, a per-call random int, logged). The object a1 has a fake vtable with slot +0x2c (five args, logged). The
target this+0x34 is null in about three cases in ten. The 40-byte cells are random bytes, so the stored values are checked by the heap comparison."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d8d60(c):
    from recruits_util import clear_hooks,pystub,_HOOKED
    clear_hooks(c)
    e = c.emu
    e.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32)))
    null_arr = c.rng.random() < 0.2

    def hdc90(em, r):
        em.calllog.append(('45dc90', 0, None, tuple(em.arg32(k) for k in range(4))))
        em.ret(eax=0, argbytes=16)
    e.hook(0x45dc90, hdc90)
    _HOOKED.add(0x45dc90)

    rvals = [c.rng.randrange(-100000, 100000) for _ in range(64)]  # fixed per case: both runs must see the same values
    ri = [0]

    def h1bc(em, r):
        em.calllog.append(('1bc', 0, None, (em.arg32(0), em.arg32(1))))
        v = rvals[ri[0] % len(rvals)]
        ri[0] += 1
        em.ret(eax=v & 0xffffffff, argbytes=8)

    def h2c(em, r):
        em.calllog.append(('2c', 0, None, tuple(em.arg32(k) for k in range(5))))
        em.ret(eax=0, argbytes=20)

    vt_eng = e.fake_vtable('d8d60_eng', 200, {0x1bc: h1bc})
    vt_a1 = e.fake_vtable('d8d60_a1', 200, {0x2c: h2c})
    eng = _rnd(c, 0x2000)
    e.w32(eng, vt_eng)
    e.w32(0x70039c, eng)
    a1 = _rnd(c, 0x40)
    e.w32(a1, vt_a1)
    tgt = 0 if c.rng.random() < 0.3 else _rnd(c, 0x40)
    arr = _rnd(c, 0x400)
    self_obj = _rnd(c, 0x100)
    e.w32(self_obj + 0x20, 0 if null_arr else arr)
    e.w32(self_obj + 0x18, c.rng.randrange(0, 4))
    e.w32(self_obj + 0x1c, c.rng.randrange(0, 3))
    d_m = c.rng.choice([1, 2, 3, 5, 7, 9, -2, -3, -5])
    d_D = c.rng.choice([1, 2, 3, 4, 5, 7, -2, -3, -4])
    e.w32(self_obj + 0x30, d_m & 0xffffffff)
    e.w32(self_obj + 0x40, d_D & 0xffffffff)
    e.w32(self_obj + 0x3c, c.rng.randrange(-50, 51) & 0xffffffff)
    e.w32(self_obj + 0x44, c.rng.randrange(-20, 21) & 0xffffffff)
    e.w32(self_obj + 0x24, c.rng.getrandbits(32))
    e.w32(self_obj + 0x34, tgt)
    a2 = c.rng.getrandbits(32)
    a3 = c.rng.getrandbits(32)
    a4 = c.rng.getrandbits(32)
    return [self_obj, a1, a2, a3, a4]


S(0x5d8d60, 'unnamed_5d8d60 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_d8d60,
  note='unclaimed-57 batch 114; 0x45dc90 hooked (early path); engine slot +0x1bc and object slot +0x2c fake')
