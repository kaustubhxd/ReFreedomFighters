"""specs_s37013.py - cascade s6 batch 37013: 0x51d6f0. Table at [[0x70039c]+0x9b]: slot 0x58 (id -> object with +8 sub-object) and slot 0x60 (handle -> effect record);
hooked 0x4db2c0, 0x43ec00 (returns a handle), 0x46b440 (floats recorded as raw dwords)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g51d6f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    hook_rec(c, 0x4db2c0, 2, this=True, nullflag=(0, 1))
    hook_rec(c, 0x43ec00, 6, this=True, nullflag=(0, 1), ret=lambda em, k: r.choice([0, 0x11, 0x22, r.getrandbits(32)]))
    hook_rec(c, 0x46b440, 2, this=True)
    ids = [r.randint(1, 0xfffff), r.randint(1, 0xfffff)]
    objs = {i: (rnd(c, 0x20) if r.random() < 0.85 else 0) for i in ids}
    effs = {}

    def eff(h):
        if h not in effs:
            effs[h] = rnd(c, 0x90) if r.random() < 0.8 else 0
        return effs[h]

    def t58(em, k):
        return objs.get(em.arg32(0), 0)

    def t60(em, k):
        return eff(em.arg32(0))
    for h in (0x11, 0x22, 0x77, 0x99):
        eff(h)
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=t58), 0x60: pystub(c, 1, this=True, ret=t60)}, table_size=0x20)
    me = rnd(c, 0x4d0)
    e.w32(me + 0x469, r.choice([0, 1, 1, 5]))
    e.w32(me + 0x409, r.choice([ids[0], 0]) if r.random() < 0.9 else ids[0])
    e.w32(me + 0x40d, r.choice([ids[1], 0]) if r.random() < 0.9 else ids[1])
    for off in (0x4a1, 0x49d):
        e.w32(me + off, r.choice([0, 0, 0x77, 0x99, 0x11]))
    return [me]


S(0x51d6f0, 'GUESS start or fade two effects', 'thiscall', None, ret=None, gen=_g51d6f0, note='batch37013')
