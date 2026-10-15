"""specs_s67565.py - cascade s6 batch 67565 (0x534fd0, thiscall(owner, kind) ret 8, returns eax). The object table (sys[0x9b]) has slots 0x60 (handle -> record, a random 0x100-byte block) and 0x4c (1 arg); its
+0xadc is a random dword; sys[0x1c] is a random dword; this slot 0x4c (bool) decides success; 0x533e00 (handle or 0) / 0x44b610 / 0x44b740 are hooks."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g534fd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    recs = [rnd(c, 0x100) for _ in range(3)]
    so = sysobj(c, table_slots={0x60: pystub(c, 1, this=True, ret=lambda em, k: recs[k % 3]),
                                0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0xb00)
    hook_rec(c, 0x533e00, 0, this=True, ret=lambda em, k: r.choice([0, 7, 9]))
    hook_rec(c, 0x44b610, 0, this=True)
    hook_rec(c, 0x44b740, 1, pop=0)
    t = obj(c, 0x120, {0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100]))})
    return [t, r.getrandbits(32), r.choice([0, 1, 4, 4, 5, 0x7f])]


S(0x534fd0, 'GUESS create_effect_record', 'thiscall', None, ret='eax', gen=_g534fd0, note='batch67565')
