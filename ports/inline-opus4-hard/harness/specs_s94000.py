"""specs_s94000.py - hard trial opus 4: 0x570cb0 (mission-select handler, 9-way jump table on block[0x4a] - '1').
Every case-body callee is hooked (hook_rec, ECX + args + call order compared): 0x5b1000, 0x5b1440, 0x59cb60 (the level name
is a pointer to the caller's stack in one path, so it is compared by content: 5 bytes), 0x4947c0, 0x561be0, 0x562bc0.
Engine: table object (+0x9b) slot 0xb4 and optional object at +0x1a9f slot 0x138 are recorders. Assert hook always set."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _al(r):
    return r.choice([0, 0, 1, 0x100, 0xff, r.getrandbits(32), r.getrandbits(8) << 8])


def _g570cb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    rets = [_al(r) for _ in range(3)]
    hook_rec(c, 0x5b1000, 1, this=True, ret=rets[0])
    hook_rec(c, 0x5b1440, 1, this=True, ret=rets[1])
    hook_rec(c, 0x59cb60, 1, this=True, deref={0: -5}, ret=r.getrandbits(32))
    hook_rec(c, 0x4947c0, 1, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x561be0, 0, this=True, ret=rets[2])
    hook_rec(c, 0x562bc0, 0, this=True, ret=r.getrandbits(32))
    so = sysobj(c, table_slots={0xb4: pystub(c, 1, this=True, ret=r.getrandbits(32))}, table_size=0x100)
    if r.random() < 0.7:
        o = obj(c, 0x20, {0x138: pystub(c, 1, this=True, ret=r.getrandbits(32))})
        e.wbytes(so + 0x1a9f, o.to_bytes(4, 'little'))
    else:
        e.wbytes(so + 0x1a9f, bytes(4))
    blk = rnd(c, 0x600)
    x = r.random()
    if x < 0.7:
        d = r.choice(b'123456789')
    elif x < 0.8:
        d = r.choice([0x30, 0x3a, 0x38, 0x31, 0x39])
    elif x < 0.9:   # sign edge: 0x80+ is negative after movsx, and 0xb1..0xb9 alias '1'..'9' in the low 7 bits
        d = r.choice([0x80, 0xff, 0xb0, 0xb1, 0xb5, 0xb8, 0xb9, 0xba, 0x00, 0x7f])
    else:
        d = r.getrandbits(8)
    e.w8(blk + 0x4a, d)
    me = rnd(c, 0x100)
    e.w32(me + 0x94, blk)
    return [me]


S(0x570cb0, 'MissionSelect_570cb0', 'thiscall', None, ret=None, gen=_g570cb0)
