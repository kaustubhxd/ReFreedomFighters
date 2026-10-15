"""specs_s5815.py - unclaimed-57, batch 115: 0x5c4e50 (GUESS name unnamed_5c4e50). Thiscall, one stack argument obj (ret 4), returns al = 1. The assert hook
0x7003b0 is a logging stub (always set). The readers 0x4e5e60 (two dwords) and 0x4e6180 (two float arrays, writing two floats each) are hooked: they
ignore ECX (the original passes NULL, which the readers would fault on), and return per-call values. The allocator 0x41e290 (cdecl) returns a fresh
allocation, or 0 for the overflow size. The argument object obj has fake slots +0x58 and +0x48/+0x6c/+0x68 (one arg each, logged: a pointer into the
array is logged as its offset, otherwise its tag) and +0x40 (one pointer to the argument's own slot: in half the cases it writes a new object pointer
there, which the next call reads). The engine sub-object slot +0x58 (one arg, logged) returns a per-case value. The holder (this+0x44 ->+0x18) has
slot +0x14 (returns a per-case value)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d4e50(c):
    e = c.emu
    rv = [c.rng.getrandbits(32) for _ in range(8)]
    ri = [0]
    fl = [c.rng.choice([0.0, 1.0, -2.5, 0.125, 3.75, 16.0]) for _ in range(4)]
    cnt = c.rng.choice([0, 1, 2])
    rewrite = c.rng.random() < 0.5
    newobj = _rnd(c, 0x40)
    r58 = c.rng.getrandbits(32)
    r14 = c.rng.getrandbits(32)
    rd = [c.rng.getrandbits(32), c.rng.getrandbits(32)]
    rdi = [0]
    arr_holder = {}

    def hassert(em, r):
        em.calllog.append(('assert', 0, None, ()))
        em.ret(eax=0)
    e.w32(0x7003b0, e.stub_fn('assert', hassert))

    def hread(em, r):
        k = rdi[0]
        rdi[0] += 1
        em.ret(eax=rd[k % 2], argbytes=0)
    e.hook(0x4e5e60, hread)

    def hfl(em, r):
        import struct
        out = em.arg32(0)
        for i in range(cnt):
            em.wbytes(out + 4 * i, struct.pack('<f', fl[i]))
        em.ret(eax=cnt, argbytes=4)
    e.hook(0x4e6180, hfl)

    def halloc(em, r):
        size = em.arg32(0)
        em.calllog.append(('41e290', 0, None, (size,)))
        if size == 0xffffffff:
            em.ret(eax=0, argbytes=0)
            return
        p = em.alloc(max(size, 4), 4)
        arr_holder['arr'] = p
        em.ret(eax=p, argbytes=0)
    e.hook(0x41e290, halloc)

    def h58(em, r):
        p = em.arg32(0)
        arr = arr_holder.get('arr', 0)
        rel = p - arr if arr and arr <= p < arr + 0x400 else 'other'
        em.calllog.append(('58', 0, None, (rel,)))
        em.ret(eax=0, argbytes=4)

    def h40(em, r):
        p = em.arg32(0)
        em.calllog.append(('40', 0, None, ()))
        if rewrite:
            em.w32(p, newobj)
        em.ret(eax=0, argbytes=4)

    def hwrite(name):
        def h(em, r):
            p = em.arg32(0)
            arr = arr_holder.get('arr', 0)
            rel = p - arr if arr and arr <= p < arr + 0x400 else 'other'
            em.calllog.append((name, 0, None, (rel,)))
            em.ret(eax=0, argbytes=4)
        return h

    def hsub58(em, r):
        em.calllog.append(('s58', 0, None, (em.arg32(0),)))
        k = ri[0]
        ri[0] += 1
        em.ret(eax=rv[k % 8], argbytes=4)

    def hholder14(em, r):
        em.calllog.append(('h14', 0, None, ()))
        em.ret(eax=r14, argbytes=0)

    vt_obj = e.fake_vtable('c4e50_obj', 200, {0x58: h58, 0x40: h40, 0x48: hwrite('48'), 0x6c: hwrite('6c'), 0x68: hwrite('68')})
    vt_sub = e.fake_vtable('c4e50_sub', 200, {0x58: hsub58})
    vt_h = e.fake_vtable('c4e50_h', 200, {0x14: hholder14})
    obj = _rnd(c, 0x40)
    e.w32(obj, vt_obj)
    e.w32(newobj, vt_obj)
    holder = _rnd(c, 0x40)
    e.w32(holder, vt_h)
    owner = _rnd(c, 0x40)
    e.w32(owner + 0x18, holder)
    sub = _rnd(c, 0x40)
    e.w32(sub, vt_sub)
    eng = _rnd(c, 0x2000)
    e.w32(eng + 0x9b, sub)
    e.w32(0x70039c, eng)
    self_obj = _rnd(c, 0x100)
    e.w32(self_obj + 0x44, owner)
    arr_holder.clear()
    return [self_obj, obj]


S(0x5c4e50, 'unnamed_5c4e50 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_d4e50,
  note='unclaimed-57 batch 115; assert 0x7003b0 logs; readers 0x4e5e60 and 0x4e6180 hooked (ignore ECX); operator new hooked; obj slots fake; sub and holder fake')
