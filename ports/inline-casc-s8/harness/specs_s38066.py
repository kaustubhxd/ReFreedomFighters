"""specs_s38066.py - cascade s8 batch 38066: 0x555830. thiscall(arg) ret 4. this = cache (+0x14 count 0..6, +0x18 entry pointers: null, objects whose +0x30 matches the key or not, +0x48 zero or not).
arg+4 = tag cell (0x5003d0 hook call 0 returns it: dword id, byte tag 0/1 mostly, sometimes other -> 0x104 error + assert), arg+8 = struct {A, idx, count}; A = {array of 8-byte entries, .., count at +8}. The table slot 0x58
returns 0 (error 0x468), a key matching a cache entry, or a fresh key object whose slot 0x100 returns a new object or 0 (error 0x475). 0x5003d0 / 0x5002f0 hooked; the logger stream has a custom printer
(logs its arguments), the assert hook logs its calls and is always set."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g555830(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def prn(em, res_):
        a1 = em.arg32(1)
        em.calllog.append(('log', em.arg32(0) != 0, a1) + ((em.arg32(2),) if a1 == 0x69c6b0 else ()))
        em.ret(eax=0)
    st = obj(c, 0x20, {0x2c: e.stub_fn('printer', prn)})

    def lg(em, res_):
        em.calllog.append(('logger', em.reg('ecx') != 0, em.arg32(0), em.arg32(1)))
        em.ret(eax=st, argbytes=8)
    e.w32(0x700390, obj(c, 0x40, {0x20: e.stub_fn('logger', lg)}))
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def newobj():
        o = e.alloc(0x60, 4)
        e.wbytes(o, r.randbytes(0x60))
        if r.random() < 0.5:
            e.w32(o + 0x48, 0)
        return o
    fresh = obj(c, 0x110, {0x100: pystub(c, 1, this=True, ret=lambda em, k: (newobj() if r.random() < 0.8 else 0))})
    ncache = r.choice([0, 1, 2, 3, 5, 6])
    this = e.alloc(0x50, 4)
    e.wbytes(this, r.randbytes(0x50))
    e.w32(this + 0x14, ncache)
    keyobj = None
    mode = r.random()
    entries = []
    for i in range(ncache):
        k = r.random()
        if k < 0.15:
            entries.append(0)
        else:
            o = newobj()
            entries.append(o)
    if mode < 0.12:
        keyobj = 0
    elif mode < 0.6 and [x for x in entries if x]:
        keyobj = r.choice([x for x in entries if x])
        # entry with +0x30 == keyobj? the key is the +0x30 field value, the key object itself is a separate vtable object
        kobj = obj(c, 0x110, {0x100: pystub(c, 1, this=True, ret=0)})
        for x in entries:
            if x and r.random() < 0.4:
                e.w32(x + 0x30, kobj)
        e.w32(keyobj + 0x30, kobj)
        keyobj = kobj
    else:
        keyobj = fresh
    for i, x in enumerate(entries):
        e.w32(this + 0x18 + 4 * i, x)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: keyobj)})
    cell = e.alloc(0x10, 4)
    e.wbytes(cell, r.randbytes(0x10))
    e.wbytes(cell + 4, bytes([r.choice([0, 1, 1, 0, 2, 9])]))
    cell2 = e.alloc(0x10, 4)
    e.wbytes(cell2, r.randbytes(0x10))
    arr = e.alloc(8 * 5, 4)
    e.wbytes(arr, r.randbytes(8 * 5))
    for i in range(5):
        e.wbytes(arr + 8 * i + 4, bytes([r.choice([0, 1, 0, 1, 3, 0x80])]))
    A = e.alloc(0x10, 4)
    e.wbytes(A, r.randbytes(0x10))
    e.w32(A, arr)
    e.w32(A + 8, r.choice([0, 1, 2, 3, 5]))
    Sx = e.alloc(0x10, 4)
    e.wbytes(Sx, r.randbytes(0x10))
    e.w32(Sx, A)
    e.w32(Sx + 4, r.choice([0, 1, 2, 3, 4]))
    e.w32(Sx + 8, r.choice([0, 1, 1, 2]))
    argp = e.alloc(0x10, 4)
    e.wbytes(argp, r.randbytes(0x10))
    e.w32(argp + 4, cell)
    e.w32(argp + 8, Sx)
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=lambda em, k: cell if k == 0 else cell2)
    hook_rec(c, 0x5002f0, 1, this=True, pop=4)
    return [this, argp]


S(0x555830, 'GUESS find/create cached object and flag slot', 'thiscall', None, ret=None, gen=_g555830, note='batch38066')
