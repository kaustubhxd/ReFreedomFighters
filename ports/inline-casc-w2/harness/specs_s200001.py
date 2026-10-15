"""specs_s200001.py - Sonnet-w2 batch 200001: SEH-framed small functions. Fake outer SEH records (seh_chain, 0-2) under fs:[0];
every hooked callee records the chain it sees (seh_record: next, handler, state); pilot compares fs:[0] after return (out['seh'])."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, seh_record, seh_chain


def _chain(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))


def _assert_hook(c):
    r = c.rng
    side = seh_record(c, 2)
    n = [0]

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        side(e2, n[0])
        n[0] += 1
        e2.ret(eax=r.getrandbits(32))
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))


def g48aa80(c):
    _chain(c)
    _assert_hook(c)
    return []


def _engine(c, slots_obj):
    eng = rnd(c, 0x1b00)
    c.emu.w32(0x70039c, eng)
    c.emu.w32(eng + 0x9b, slots_obj)
    return eng


def g45c510(c):
    _chain(c)
    r = c.rng
    u = obj(c, 0x40, {0x14: pystub(c, 1, ret=r.getrandbits(32), this=True, side=seh_record(c, 2))}, nslots=0x10)
    t = rnd(c, 0x40)
    c.emu.w32(t + 8, u)
    _engine(c, t)
    return [r.choice([0, 1, 0xffffffff, r.getrandbits(32)])]


def g4f6b20(c):
    _chain(c)
    r = c.rng
    t = obj(c, 0x40, {0x34: pystub(c, 1, ret=r.getrandbits(32), this=True, side=seh_record(c, 2))}, nslots=0x14)
    _engine(c, t)
    return [rnd(c, 0x60)]


S(0x48aa80, 'GUESS call assert hook in SEH frame', 'cdecl', None, ret='eax', gen=g48aa80, note='batch200001')
S(0x45c510, 'GUESS engine table obj slot 0x14', 'cdecl', None, ret='eax', gen=g45c510, note='batch200001')
S(0x4f6b20, 'GUESS init and register', 'thiscall', None, ret='eax', gen=g4f6b20, note='batch200001')
