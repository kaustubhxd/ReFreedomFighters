"""specs_s1603.py - soundtimers batch 1603: FFActor_If.PlaySound_Enum and PlaySound_Enum_GetTime natives.
The parameter accessor 0x5003d0 runs as exe code on real view/stack structures; the actor's PlaySound_Enum (vtable
+0x6e8) is a stub returning a handle that the SRefToPtr stub maps to a sound object (or not)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks, sound_obj


def view(c, nslots, types=None):
    """AppendStack view {stack*, base, count} over a stack {data*, ?, size}; slot = (value, type byte)."""
    r = c.rng
    base = r.randint(0, 3)
    size = base + nslots + r.randint(0, 2)
    data = rnd(c, 8 * size)
    st = rnd(c, 0x10)
    c.emu.w32(st, data)
    c.emu.w32(st + 8, size)
    v = rnd(c, 0x10)
    c.emu.w32(v, st)
    c.emu.w32(v + 4, base)
    c.emu.w32(v + 8, nslots)
    for i, t in enumerate(types or []):
        c.emu.w8(data + 8 * (base + i) + 4, t)
    return v, data + 8 * base


def _frame(c, getTime):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    h = r.getrandbits(32)
    so = sound_obj(c) if r.random() < 0.7 else 0
    db = obj(c, 0x40, {0x60: stub(c, seq, 1, ret=0, retfn=[(0, h, so)])})
    sysobj(c, db=db)
    ret = h if r.random() < 0.8 else r.getrandbits(32)
    actor = obj(c, 0x40, {0x6e8: stub(c, seq, 3, ret=ret)})
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x1c, actor)
    args, a0 = view(c, 1)
    params = rnd(c, 0x20)
    c.emu.w32(params + 4, args)
    if getTime:
        k = r.random()
        ty = r.choice([0, 2]) if k < 0.9 else r.choice([1, 3, 5])
        res, s0 = view(c, 1, [ty])
        c.emu.w32(params + 8, res)
        # the "wrong type" path: logger at 0x700390 and handler at 0x7003b0
        ch = obj(c, 0x20, {0x2c: stub(c, seq, 3, pop=False)})   # cdecl (this, fmt, msg): caller pops
        log = obj(c, 0x20, {0x20: stub(c, seq, 2, ret=ch)})
        c.emu.w32(0x700390, log)
        hd = stub(c, seq, 0)
        c.emu.w32(0x7003b0, hd)
    return [me, params]


S(0x55baa0, 'ZFFActorIf::PlaySound_EnumBased', 'thiscall', None, ret=None, gen=lambda c: _frame(c, False),
  note='batch1603; PlaySound_Enum(arg0, false, 0)')
S(0x55bad0, 'ZFFActorIf::PlaySound_EnumBased_GetTime', 'thiscall', None, ret=None, gen=lambda c: _frame(c, True),
  note='batch1603; plays the shout, returns the sound length (+0x70) or 0.0 as a float result')
