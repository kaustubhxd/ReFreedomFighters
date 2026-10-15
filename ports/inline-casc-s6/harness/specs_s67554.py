"""specs_s67554.py - cascade s6 batch 67554 (0x5b0360, thiscall() plain ret, return value unused). The table object (sys[0x9b]) has slots 0x138 (returns a config object whose slot 0x88 writes an id into
the caller's stack variable) and 0x58 (maps the id); 0x5aee60 / 0x5afbb0 / 0x5af350 / 0x5af2a0 / 0x5af5b0 are hooks (stack `this` marked); 0x5aede0 / 0x65e090 (trivial initialisers) run unhooked."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g5b0360(c):
    clear_hooks(c)
    r = c.rng
    ids = [r.getrandbits(32) for _ in range(4)]

    def s88(em, k):
        em.wbytes(em.arg32(1), ids[k % 4].to_bytes(4, 'little'))
    cfg = obj(c, 0x20, {0x88: pystub(c, 2, this=True, stackmark=(1,), side=s88)})
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=cfg),
                           0x58: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))})
    hook_rec(c, 0x5aee60, 1, this='mark')
    hook_rec(c, 0x5afbb0, 2, this='mark', stackmark=(1,))
    hook_rec(c, 0x5af350, 1, this='mark', ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x5af2a0, 2, this='mark')
    hook_rec(c, 0x5af5b0, 3, this='mark')
    return [rnd(c, 0x40)]


S(0x5b0360, 'GUESS init_entries_from_config', 'thiscall', None, ret=None, gen=_g5b0360, note='batch67554')
