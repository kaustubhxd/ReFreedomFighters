"""specs_s1634.py - soundtimers batch 1634: ZDllSound::DeleteSounds (list iterator Python model; the two free functions
and the log object are hooks)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks, hook


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    n = r.randint(0, 6)
    refs = [r.getrandbits(32) | 1 for _ in range(n)]
    objs = {}
    for ref in refs:
        o = rnd(c, 0x100)
        c.emu.w32(o + 0x2c, r.choice([0, 1, 2, 3]))
        objs[ref] = o
    st = {'i': 0}

    def sref(e, rr):
        ref = e.r32(e.reg('esp') + 4)
        e.ret(eax=objs.get(ref, 0), argbytes=4)
    dbslot = c.emu.stub_fn('SRefToPtr', sref)

    def it4c(e, rr):
        st['i'] = 0
        e.ret(eax=0, argbytes=4)

    def it5c(e, rr):
        out = e.r32(e.reg('esp') + 4)
        cur = refs[st['i']] if st['i'] < len(refs) else 0
        st['i'] += 1
        nxt = refs[st['i']] if st['i'] < len(refs) else 0
        e.w32(out, nxt)
        e.ret(eax=cur, argbytes=4)
    lst = obj(c, 0x40, {0x4c: c.emu.stub_fn('it4c', it4c), 0x5c: c.emu.stub_fn('it5c', it5c)})
    db = obj(c, 0x80, {0x60: dbslot})
    sysobj(c, db=db)
    ch = obj(c, 0x40, {0x2c: stub(c, seq, 3, pop=False)})
    lg = obj(c, 0x40, {0x20: stub(c, seq, 2, ret=ch)})
    c.emu.w32(0x700390, lg)
    hook(c, seq, 0x44b610, 0)
    hook(c, seq, 0x44b740, 1, this=False, pop=False)
    d = rnd(c, 0x5400)
    c.emu.w32(d + 0x53b2, c.emu.r32(lst))
    group = r.choice([0, 1, 2, 3, -1])
    return [d, group]


S(0x535ac0, 'ZDllSound::DeleteSounds', 'thiscall', None, ret=None, gen=_gen, note='batch1634')
