"""specs_s35049.py - 0x513340 (stdcall(o) ret 4, ret='al'). Object slots 0x1e0 (1 arg recorded; AL results per call: true/false with random garbage in the upper bytes), 0x438 (AL random byte incl. values > 1),
0x674 (EAX zero in a third), 0x670 (AL true/false)."""
from pilot import S
from recruits_util import obj, clear_hooks, pystub


def _g513340(c):
    clear_hooks(c)
    r = c.rng

    def al():
        return (r.getrandbits(24) << 8) | r.choice([0, 0, 1, 2, 0x80, r.getrandbits(8)])
    res = [al(), al()]
    o = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: res[min(k, 1)]), 0x438: pystub(c, 0, this=True, ret=al()),
                      0x674: pystub(c, 0, this=True, ret=0 if r.random() < 1 / 3 else r.getrandbits(32) | 1), 0x670: pystub(c, 0, this=True, ret=al())}, nslots=0x11e)
    return [o]


S(0x513340, 'GUESS object state predicate', 'stdcall', None, ret='al', gen=_g513340, note='batch35049')
