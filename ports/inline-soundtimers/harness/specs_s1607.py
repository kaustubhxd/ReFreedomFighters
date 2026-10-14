"""specs_s1607.py - soundtimers batch 1607: OSD forwarders for subtitles / action markers, CActorActionMarker::Add."""
import struct
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook


def _t(c):
    r = c.rng
    k = r.random()
    if k < 0.6:
        return r.uniform(0, 5)
    return r.choice([0.0, -0.0, -1.5, float('nan'), float('inf'), r.uniform(-5, 5)])


def _fbits(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _fwd(c, off, target):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, target, 3)
    me = rnd(c, off + 0x10)
    c.emu.w32(me + off, rnd(c, 0x20) if r.random() < 0.85 else 0)
    return [me, r.getrandbits(32), r.getrandbits(32), _fbits(_t(c))]


S(0x59a5b0, 'ZGameOSD::MessageDialog', 'thiscall', None, ret=None, gen=lambda c: _fwd(c, 0x1d0f, 0x5aaa50),
  note='batch1607; forwards when +0x1d0f is set')
S(0x5aaa50, 'ZOnScreenDisplay::MessageDialog', 'thiscall', None, ret=None, gen=lambda c: _fwd(c, 0x64c, 0x5ef950),
  note='batch1607')
S(0x598e10, 'ZGameOSD::AddActorActionMarker', 'thiscall', None, ret=None, gen=lambda c: _fwd(c, 0x22d7, 0x5eab20),
  note='batch1607')


def _add(c):
    r = c.rng
    clear_hooks(c)
    me = rnd(c, 0x50)
    n = r.choice([0, 1, 2, 5, 15, 16]) if r.random() < 0.5 else r.randint(0, 16)
    actors = []
    for i in range(17):
        e = rnd(c, 0x18)
        a = rnd(c, 4) if i < n else e   # unused slots hold garbage actor fields
        c.emu.w32(e, a)
        c.emu.w32(e + 4, r.choice([0, 1, 2, 3]))
        c.emu.w32(me + 4 + 4 * i, e) if i < 16 else None
        if i < n:
            actors.append(a)
    if n < 16:
        pass
    c.emu.w32(me + 0x44, n)
    actor = r.choice(actors) if actors and r.random() < 0.6 else rnd(c, 4)
    return [me, actor, r.choice([0, 1, 2, 3, r.getrandbits(32)]), _fbits(_t(c))]


S(0x5eab20, 'CActorActionMarker::Add', 'thiscall', None, ret=None, gen=_add,
  note='batch1607; 16-slot marker list, update in place, negative time flag')
