"""specs_s5796.py - unclaimed-57, batch 96: 0x5c4c00 (GUESS name unnamed_5c4c00). Thiscall, two stack arguments (a1 unused, db; ret 8), no return.
Hooked callees: 0x4e5e60 (the first call returns a random dword; the second returns a count from 0 to 8, so the cap at 5 runs), 0x4e6180 (float
array reader: writes a count from the dword at ECX mod 6 through its pointer), 0x41e290 (cdecl operator new: returns a fresh allocation of the
requested size, or 0 for the overflow size 0xffffffff, which runs the null branch). The holder object (this+0x44 ->+0x18) has a fake slot +0x14
(no args, returns a per-case dword)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _c4c00(c):
    e = c.emu
    v1 = c.rng.getrandbits(32)
    n_target = c.rng.randrange(0, 9)
    calls = [0]
    r58 = c.rng.getrandbits(32)
    ov = c.rng.random() < 0.1

    def h5e60(em, r):
        calls[0] += 1
        em.ret(eax=v1 if calls[0] == 1 else n_target, argbytes=0)
    e.hook(0x4e5e60, h5e60)

    def h6180(em, r):
        out = em.arg32(0)
        count = em.r32(em.reg('ecx')) % 6
        floats = [0.0, 1.0, -2.5, 0.125, 3.75, 16.0]
        import struct
        for i in range(count):
            em.wbytes(out + 4 * i, struct.pack('<f', floats[i]))
        em.ret(eax=count, argbytes=4)
    e.hook(0x4e6180, h6180)

    def h41e290(em, r):
        size = em.arg32(0)
        em.calllog.append(('41e290', 0, None, (size,)))
        if size == 0xffffffff or (ov and size == 0):
            em.ret(eax=0, argbytes=0)
            return
        em.ret(eax=em.alloc(max(size, 4), 4), argbytes=0)
    e.hook(0x41e290, h41e290)

    def h14(em, r):
        em.calllog.append(('14', 0, None, ()))
        em.ret(eax=r58, argbytes=0)

    vt_h = e.fake_vtable('c4c00_h', 160, {0x14: h14})
    holder = _rnd(c, 0x40)
    e.w32(holder, vt_h)
    o_obj = _rnd(c, 0x40)
    e.w32(o_obj + 0x18, holder)
    self_obj = _rnd(c, 0x200)
    e.w32(self_obj + 0x44, o_obj)
    a1 = c.rng.getrandbits(32)
    db = _rnd(c, 0x40)
    return [self_obj, a1, db]


S(0x5c4c00, 'unnamed_5c4c00 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_c4c00,
  note='unclaimed-57 batch 96; readers 0x4e5e60 and 0x4e6180 hooked; operator new 0x41e290 hooked (fresh allocation, or null); holder slot +0x14 fake')
