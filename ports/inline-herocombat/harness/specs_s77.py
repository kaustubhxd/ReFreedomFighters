"""specs_s77.py - main thread batch 77: ZFFHERO IsRunning, IsSneaking, SetMoveSpeeds and the three focus forwarders.
The camera helper (+0x85a) is a recorder object: slots 0x88, 0x8c, 0x90 log their arguments and return a random eax."""
from pilot import S
from kit76 import obj, rnd


def _flags(c):
    r = c.rng
    hero = rnd(c, 0x700)
    f = r.getrandbits(32)
    f = r.choice([f, f & ~0x10000000, f & ~0x400, f & ~0x402, f | 2, f & ~2, 2, 0x402, 0x10000002])
    c.emu.w32(hero + 0x417, f)
    return [hero]


S(0x592c20, 'ZFFHERO::IsRunning', 'thiscall', None, ret='eax', gen=_flags, note='b77')
S(0x592c40, 'ZFFHERO::IsSneaking', 'thiscall', None, ret='al', gen=_flags, note='b77')


def _speeds(c):
    return [rnd(c, 0x700), rnd(c, 12)]


S(0x594f70, 'ZFFHERO::SetMoveSpeeds', 'thiscall', None, gen=_speeds, note='b77')


def _fwd(nargs):
    def gen(c):
        r = c.rng
        e = c.emu
        hero = rnd(c, 0x900)
        rv = r.getrandbits(32)
        h = obj(e, 'camhelper', 0x20, {0x88: (1, lambda e, t, a: (rv, None, (t,) + tuple(a))),
                                       0x8c: (2, lambda e, t, a: (rv, None, (t,) + tuple(a))),
                                       0x90: (2, lambda e, t, a: (rv, None, (t,) + tuple(a)))})
        e.w32(hero + 0x85a, h)
        c.emu.mu.ctl_flush_tb()
        return [hero] + [r.getrandbits(32) for _ in range(nargs)]
    return gen


S(0x591d10, 'ZFFHERO::GetFocusMatPos', 'thiscall', None, ret='eax', gen=_fwd(2), note='b77; helper slot 0x8c recorder')
S(0x591d60, 'ZFFHERO::GetGlobalFocalPoint', 'thiscall', None, ret='eax', gen=_fwd(1), note='b77; helper slot 0x88 recorder')
S(0x5922a0, 'ZFFHERO::GetRootFocusMatPos', 'thiscall', None, ret='eax', gen=_fwd(2), note='b77; helper slot 0x90 recorder')
