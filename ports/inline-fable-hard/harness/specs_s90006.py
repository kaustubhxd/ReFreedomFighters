"""specs_s90006.py - hard trial (fable) batch 90006: 0x5a3710 multiplayer manager ctor. Engine object with the settings object (slots 0x90 writes
the "already registered" byte, 0x68/0x5c/0x40/0x58 registrations, 0x88 int read) behind table slot 0x134, table slots 0x114 (text id, random
dword so the word truncation is checked) and 0x138 (registry with slot 0x60); allocator object at 0x70038c with slot 0x20, the range function at
+8 with bounds +0xc/+0x10 around `this`, slot 0xac and the type id stored in the dword before `this`; base ctor hooked, 0x41e290 hooked
(4 prepared blocks, sometimes null), 0x4ccbe0 real."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g5a3710(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x469870, 0, this=True)
    blocks = [rnd(c, 0x20) for _ in range(4)]
    nulls = [r.random() < 0.08 for _ in range(4)]
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: 0 if nulls[min(k, 3)] else blocks[min(k, 3)])
    rets = [r.getrandbits(32) for _ in range(48)]
    n = [0]

    def nxt(em, k):
        v = rets[n[0] % len(rets)]
        n[0] += 1
        return v
    have = r.choice([0, 0, 1, 0xff])
    ival = r.choice([0, 1, 0x100, r.getrandbits(32)])

    def w90(em, k):
        em.wbytes(em.arg32(1), bytes([have]))

    def w88(em, k):
        em.w32(em.arg32(1), ival)
    z = obj(c, 0x20, {0x90: pystub(c, 2, this=True, stackmark=(1,), side=w90, ret=nxt),
                      0x68: pystub(c, 3, this=True, ret=nxt), 0x5c: pystub(c, 3, this=True, ret=nxt),
                      0x40: pystub(c, 3, this=True, ret=nxt), 0x58: pystub(c, 3, this=True, ret=nxt),
                      0x88: pystub(c, 2, this=True, stackmark=(1,), side=w88, ret=nxt)})
    reg = obj(c, 0x20, {0x60: pystub(c, 3, this=True, ret=nxt)})
    so = sysobj(c, table_slots={0x134: pystub(c, 0, this=True, ret=z), 0x114: pystub(c, 4, this=True, ret=nxt),
                                0x138: pystub(c, 0, this=True, ret=reg)}, table_size=0x140)
    e.wbytes(so + 0x1b5d, bytes(r.getrandbits(8) for _ in range(4)))
    blk = rnd(c, 0x160)
    E = blk + 8
    e.w32(E - 4, r.choice([0, 0, r.getrandbits(32)]))
    al = obj(c, 0x20, {0x20: pystub(c, 1, this=True, ret=r.choice([0, 0, 0, 1, r.getrandbits(32)])),
                       0xac: pystub(c, 1, this=True, ret=nxt)})
    e.w32(al + 8, 0 if r.random() < 0.3 else pystub(c, 0, this=True, ret=nxt))
    lo, hi = r.choice([(E - 0x10, E + 0x100), (E, E + 1), (E + 1, E + 0x100), (E - 0x100, E), (0, 0xffffffff), (E - 4, E + 4)])
    e.w32(al + 0xc, lo & 0xffffffff)
    e.w32(al + 0x10, hi & 0xffffffff)
    e.w32(0x70038c, al)
    tbl = e.alloc(0x2c40, 4)
    e.wbytes(tbl + 0x2c1d, bytes(r.getrandbits(8) for _ in range(8)))
    e.w32(0x7003b8, tbl)
    return [E]


S(0x5a3710, 'GUESS multiplayer manager ctor', 'thiscall', None, ret='eax', gen=_g5a3710, note='batch90006')
