"""specs_s34116.py - 0x4ae3e0 (register ABI: ecx = first, edx = last): last - first = 53 * n + r with n in {0..1 (empty), 1, 2, 3, 15, 16, 17, 40, 1000} (never n = 0 with first != last: the exe loops forever); helpers are recorders that log edx."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _edx(em, k):
    em.calllog.append(('edx', em.reg('edx')))


def _g4ae3e0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4ade70, 2, this=True, ret=r.getrandbits(32), side=_edx)
    hook_rec(c, 0x4add60, 0, this=True, pop=0, ret=r.getrandbits(32), side=_edx)
    hook_rec(c, 0x4ae220, 1, this=True, ret=r.getrandbits(32), side=_edx)
    first = rnd(c, 0x100)
    n = r.choice([None, 1, 2, 3, 4, 15, 16, 17, 18, 31, 32, 33, 40, 1000])
    if n is None:
        return [first, first]
    return [first, first + 53 * n + r.choice([0, 0, 1, 25, 52, -1 if n > 1 else 0])]


S(0x4ae3e0, 'GUESS sort driver on 53-byte elements', ('regs', ['ecx', 'edx']), None, ret=None, gen=_g4ae3e0, note='batch34116')
