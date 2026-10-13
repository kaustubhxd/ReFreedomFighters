"""specs_f15b002.py - fresh slice 15 batch 2 (see src/f15b002.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook


def _r(c):
    return c.rng.getrandbits(32)


def _54a(c):
    seq = Seq(c); clear_hooks(c)
    hook(c, seq, 0x54dd00, 0, ret=_r(c))
    me = rnd(c, 0x8080)
    c.emu.w32(me + 0x8061, obj(c, 0x10, {8: stub(c, seq, 0)}) if c.rng.random() < 0.7 else 0)
    return [me]


def _57c(c):
    seq = Seq(c); clear_hooks(c)
    hook(c, seq, 0x561f50, 1, this=False)
    me = obj(c, 0x200, {0xd0: stub(c, seq, 1)})
    return [me]


def _60f(c):
    seq = Seq(c); clear_hooks(c)
    dev = obj(c, 0x10, {0xc8: stub(c, seq, 3, ret=_r(c))})
    c.emu.w32(0x724a00, dev)
    v = _r(c) if c.rng.random() < 0.6 else c.rng.choice([0, 1, 2])
    c.emu.w32(0x724938, v if c.rng.random() < 0.3 else c.rng.choice([_r(c), 0, 1, 2]))
    return [v]


def _658(c):
    clear_hooks(c)
    return [rnd(c, 0x60), c.rng.choice([0, _r(c)])]


def _659(c):
    seq = Seq(c); clear_hooks(c)
    p = rnd(c, 0x20)
    c.emu.w32(p + 0x18, obj(c, 0x10, {0: stub(c, seq, 1)}) if c.rng.random() < 0.7 else 0)
    return [p]


def _652(c):
    seq = Seq(c); clear_hooks(c)
    s = rnd(c, 0x1a00)
    nxt = 0
    for _ in range(c.rng.randint(0, 4)):
        o = obj(c, 0x10, {8: stub(c, seq, 0, ret=_r(c))})
        c.emu.w32(o + 8, nxt)
        nxt = o
    c.emu.w32(s + 0x190f, nxt)
    c.emu.w32(0x70039c, s)
    return []


def _4cb(c):
    seq = Seq(c); clear_hooks(c)
    sv = obj(c, 0x10, {0x4c: stub(c, seq, 1, ret=_r(c))})
    return [rnd(c, 0x60), sv]


def _ctor(base):
    def g(c):
        seq = Seq(c); clear_hooks(c)
        hook(c, seq, base, 0, ret=_r(c))
        return [rnd(c, 0x220)]
    return g


def _656(c):
    seq = Seq(c); clear_hooks(c)
    me = obj(c, 0x20, {0xc: stub(c, seq, 1, ret=_r(c)), 0x154: stub(c, seq, 2, ret=_r(c))})
    return [me, _r(c), _r(c)]


def _573a(c):
    seq = Seq(c); clear_hooks(c)
    r = obj(c, 0x10, {0x250: stub(c, seq, 0, ret=_r(c))})
    db = obj(c, 0x10, {0x58: stub(c, seq, 1, ret=r)})
    s = rnd(c, 0x100)
    c.emu.w32(s + 0x9b, db)
    c.emu.w32(0x70039c, s)
    return [rnd(c, 0x10), _r(c)]


def _572(c):
    seq = Seq(c); clear_hooks(c)
    hook(c, seq, 0x4e5e60, 0, ret=_r(c))
    hook(c, seq, 0x4e5ef0, 0, ret=_r(c))
    return [rnd(c, 0x900), rnd(c, 0x10)]


def _5734(c):
    seq = Seq(c); clear_hooks(c)
    hook(c, seq, 0x563110, 2, ret=_r(c))
    hook(c, seq, 0x573000, 1, ret=_r(c))
    return [rnd(c, 0x200), _r(c), _r(c)]


def _49c(c):
    seq = Seq(c); clear_hooks(c)
    hook(c, seq, 0x49c980, 2, ret=_r(c))
    return [rnd(c, 0x40), rnd(c, 8), _r(c)]


def _54f(c):
    seq = Seq(c); clear_hooks(c)
    c.emu.w32(0x7003a4, obj(c, 0x10, {0xc8: stub(c, seq, 1)}))
    t = obj(c, 0x10, {0x28: stub(c, seq, 0, ret=_r(c))})
    hook(c, seq, 0x557930, 0, ret=t)
    me = rnd(c, 0x20)
    c.emu.w8(me + 0xc, c.rng.choice([0, 1, 0x80]))
    return [me]


N = 'f15b002'
S(0x54a6f0, 'FUN_54a6f0 (+0x8061 slot 8, ZSynth::Render)', 'thiscall', None, ret='eax', gen=_54a, note=N + '; 0x54dd00 hooked')
S(0x57c1f0, 'ZFFAutoSave::DiscardChanges', 'thiscall', None, ret=None, gen=_57c, note=N + '; 0x561f50 hooked')
S(0x60fdb0, 'FUN_60fdb0 (cached render state 0xf)', 'thiscall', None, ret=None, gen=_60f, note=N)
S(0x658fb0, 'ZGeomDrawEntry::SetEnvironment', 'thiscall', None, ret=None, gen=_658, note=N)
S(0x659af0, 'FUN_659af0 (delete +0x18)', 'stdcall', None, ret=None, gen=_659, note=N)
S(0x6526b0, 'FUN_6526b0 (list walk slot 8)', 'cdecl', None, ret=None, gen=_652, note=N)
S(0x4cbdf0, 'ZTextureAnim::Save', 'thiscall', None, ret='al', gen=_4cb, note=N)
S(0x577830, 'FUN_577830 (ctor, vt 0x6a9768)', 'thiscall', None, ret='eax', gen=_ctor(0x573590), note=N + '; base ctor hooked')
S(0x6567b0, 'ZPrimControlBase::GetSpotLightSquareData', 'thiscall', None, ret='al', gen=_656, note=N)
S(0x573af0, 'ZBaseMap::EnableCam', 'thiscall', None, ret='eax', gen=_573a, note=N)
S(0x4b1c70, 'FUN_4b1c70 (ctor, vt 0x691c70)', 'thiscall', None, ret='eax', gen=_ctor(0x469870), note=N + '; base ctor hooked')
S(0x4baeb0, 'FUN_4baeb0 (ctor, vt 0x692b7c)', 'thiscall', None, ret='eax', gen=_ctor(0x469870), note=N + '; base ctor hooked')
S(0x5726f0, 'CSubtitle::CopyEventDataBlock', 'thiscall', None, ret='al', gen=_572, note=N + '; DBREAD hooked')
S(0x5734b0, 'CZoneMenu::OnWindowOpen', 'thiscall', None, ret='al', gen=_5734, note=N + '; callees hooked')
S(0x49cd70, 'CListUser::UnfoldList', 'thiscall', None, ret='eax', gen=_49c, note=N + '; PriUnfoldList hooked')
S(0x54fd30, 'CFFScriptInterfaceDll::End', 'thiscall', None, ret='eax', gen=_54f, note=N + '; 0x557930 hooked')
