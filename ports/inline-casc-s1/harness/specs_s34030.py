"""specs_s34030.py - cascade tier E, batch 34030.
0x4f3f70: this slots 0x2c4 (returns t) and 0xbc; t slots 0x2f0 (returns x: 0, this, or the head of a chain) and 0x2f4; chain nodes have slot 0x20 returning the next node, the last returns 0 or this.
0x4fb2f0: a slots 0x60 and 0x3c; [this+0x5c] null in a third, else a record whose +0x30 is random; engine table slot 0x4c; random bytes at +0x5a / +0x5b and flags at +4.
0x505490: hooked 0x5003d0 returns a block whose first dword is n (positive, zero or negative); engine table +0x44 holds a value; this slot 0x50 (six stack args) returns a value; 0x5057e0 and
0x5002f0 are thiscall recorders."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g4f3f70(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x40, {0x2c4: pystub(c, 0, this=True), 0xbc: pystub(c, 1, this=True)}, nslots=0x300 // 4)
    k = r.random()
    chain_end = me if r.random() < 0.5 else 0
    if k < 0.15:
        x = 0
    elif k < 0.3:
        x = me
    else:
        n = r.choice([1, 2, 3])
        nxt = chain_end
        for _ in range(n):
            nxt = obj(c, 0x20, {0x20: pystub(c, 0, ret=nxt, this=True)}, nslots=0x30 // 4)
        x = nxt
    t = obj(c, 0x20, {0x2f0: pystub(c, 0, ret=x, this=True), 0x2f4: pystub(c, 2, this=True)}, nslots=0x300 // 4)
    c.emu.w32(c.emu.r32(me) + 0x2c4, pystub(c, 0, ret=t, this=True))
    return [me, r.getrandbits(32), r.getrandbits(32)]


def _g4fb2f0(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c, table_slots={0x4c: pystub(c, 1, ret=lambda em, k: r.getrandbits(32), this=True)})
    a = obj(c, 0x20, {0x60: pystub(c, 1, this=True), 0x3c: pystub(c, 1, this=True)}, nslots=0x70 // 4)
    me = rnd(c, 0x80)
    p = 0 if r.random() < 0.33 else rnd(c, 0x40)
    c.emu.w32(me + 0x5c, p)
    return [me, a]


def _g505490(c):
    clear_hooks(c)
    r = c.rng
    e1 = rnd(c, 0x10)
    c.emu.w32(e1, r.choice([1, 5, 0x100, 0, 0xffffffff, 0x80000000, r.getrandbits(32)]))
    e2 = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, ret=lambda em, k: e1 if k == 0 else e2, this=True)
    hook_rec(c, 0x5057e0, 2, this=True)
    hook_rec(c, 0x5002f0, 1, this=True)
    so = sysobj(c, table_size=0x60)
    tbl = c.emu.r32(so + 0x9b)
    c.emu.w32(tbl + 0x44, r.getrandbits(32))
    me = obj(c, 0x20, {0x50: pystub(c, 6, ret=r.getrandbits(32), this=True)}, nslots=0x60 // 4)
    a = rnd(c, 0x20)
    return [me, a]


S(0x4f3f70, 'GUESS walk parent chain looking for this', 'thiscall', None, ret='al', gen=_g4f3f70, note='batch34030')
S(0x4fb2f0, 'GUESS push flag bytes and table value to object', 'thiscall', None, ret='al', gen=_g4fb2f0, note='batch34030')
S(0x505490, 'GUESS spawn from table offset and register result', 'thiscall', None, ret=None, gen=_g505490, note='batch34030')
