"""specs_s37114.py - cascade s6 batch 37114 (0x476c00, thiscall(stream) ret 4, returns al). The stream slots write scripted data through their out pointers (0x68 flag byte, 0x44 two
bytes, 0x48 dwords: count then a value, 0x40 ids); every slot call is logged through calllog (stack pointers as markers) because the id reads exceed the recorder rows; 0x440e10 and
the allocator 0x41e290 are hooks; the table object's slot 0x58 returns a handle per id."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g476c00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    flag = r.choice([0, 0, 1, 7])
    n = r.choice([0, 1, 2, 3, 5, 9, 0xffffffff])
    val = r.getrandbits(32)
    ids = [r.getrandbits(32) for _ in range(12)]
    cnt = {'k48': 0, 'k40': 0}

    def mark(v):
        return v if 0x20000000 <= v < 0x30000000 else 1

    def s68(em, k):
        em.calllog.append(('s68', mark(em.arg32(0))))
        em.wbytes(em.arg32(0), bytes([flag]))

    def s44(em, k):
        em.calllog.append(('s44', mark(em.arg32(0))))
        em.wbytes(em.arg32(0), (val & 0xffff).to_bytes(2, 'little'))

    def s48(em, k):
        em.calllog.append(('s48', mark(em.arg32(0))))
        em.w32(em.arg32(0), n if k == 0 else val)

    def s40(em, k):
        em.calllog.append(('s40', mark(em.arg32(0))))
        em.w32(em.arg32(0), ids[k % 12])

    def s18(em, k):
        em.calllog.append(('s18', mark(em.arg32(0)), em.arg32(1)))
    stream = obj(c, 0x20, {0x68: pystub(c, 1, this=True, side=s68), 0x44: pystub(c, 1, this=True, side=s44), 0x48: pystub(c, 1, this=True, side=s48),
                           0x40: pystub(c, 1, this=True, side=s40, stackmark=(0,)), 0x18: pystub(c, 2, this=True, side=s18)})
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0x60)
    pool = [e.alloc(0x60, 4) for _ in range(2)]
    for p in pool:
        e.wbytes(p, bytes(r.getrandbits(8) for _ in range(0x60)))
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: pool[k % 2])
    hook_rec(c, 0x440e10, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 1, 0x100]))
    t = rnd(c, 0x80)
    return [t, stream]


S(0x476c00, 'GUESS load_object_list', 'thiscall', None, ret='al', gen=_g476c00, note='batch37114')
