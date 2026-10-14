"""specs_s750.py - area 72 tail-jump forwarders. Each target is hooked by address (logs its arguments, returns a random eax).
The forwarder's own argument count equals the target's ret / 4."""
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk

TARGETS = {0x4c0e20: 1, 0x4c1060: 1, 0x4c16b0: 1, 0x4c18b0: 1, 0x4d7c30: 4}


def _hook_targets(c, e):
    for tgt, n in TARGETS.items():
        rv = c.rng.getrandbits(32)

        def h(em, r, tgt=tgt, n=n, rv=rv):
            e.calllog.append(('tgt', tgt, nostk(e.reg('ecx')), tuple(em.arg32(k) for k in range(n))))
            em.ret(eax=rv, argbytes=4 * n)
        e.hook(tgt, h)


def _gen(n):
    def g(c):
        _hook_targets(c, c.emu)
        return [_rnd(c, 0x400)] + [c.rng.getrandbits(32) for _ in range(n)]
    return g


S(0x4bf4b0, 'fwd_4c0e20', 'thiscall', None, ret='eax', gen=_gen(1), note='b750 area 72 forwarder to 0x4c0e20')
S(0x4bf4c0, 'fwd_4c1060', 'thiscall', None, ret='eax', gen=_gen(1), note='b750 area 72 forwarder to 0x4c1060')
S(0x4bf4e0, 'fwd_4c16b0', 'thiscall', None, ret='eax', gen=_gen(1), note='b750 area 72 forwarder to 0x4c16b0')
S(0x4bf4f0, 'fwd_4c18b0', 'thiscall', None, ret='eax', gen=_gen(1), note='b750 area 72 forwarder to 0x4c18b0')
S(0x4d5760, 'fwd_4d7c30', 'thiscall', None, ret='eax', gen=_gen(4), note='b750 area 72 forwarder to 0x4d7c30')
