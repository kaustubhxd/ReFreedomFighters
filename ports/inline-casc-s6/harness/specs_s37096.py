"""specs_s37096.py - cascade s6 batch 37096 (0x5ae270, thiscall(flag) ret 4, returns bool). The table object slot 0x134 returns a config object with slots 0x90 (name, &byte: writes A
then B), 0x6c (dst, name, size: fills dst with deterministic bytes), 0x88 (name, &int) and 0x5c; 0x5ae450 logs the first 7 bytes of the buffer, 0x5ae710 is a recording hook."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g5ae270(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    A = r.choice([0, 1, 1, 7])
    B = r.choice([0, 1, 1, 9])
    seq = [A, B]

    def s90(em, k):
        em.wbytes(em.arg32(1), bytes([seq[k % 2]]))

    def s6c(em, k):
        d, sz = em.arg32(0), em.arg32(2)
        em.wbytes(d, bytes((0x30 + k * 7 + i) & 0xff for i in range(sz)))

    cv = r.getrandbits(32)

    def s88(em, k):
        em.w32(em.arg32(1), cv)
    C = obj(c, 0x20, {0x90: pystub(c, 2, this=True, stackmark=(1,), side=s90), 0x6c: pystub(c, 3, this=True, stackmark=(0,), side=s6c),
                      0x88: pystub(c, 2, this=True, stackmark=(1,), side=s88), 0x5c: pystub(c, 3, this=True)})
    sysobj(c, table_slots={0x134: pystub(c, 0, this=True, ret=C)}, table_size=0x140)

    def lg(em, k):
        em.calllog.append(('buf', em.rbytes(em.arg32(0), 7)))
    hook_rec(c, 0x5ae450, 1, this=True, stackmark=(0,), side=lg)
    hook_rec(c, 0x5ae710, 1, this=True)
    t = rnd(c, 0xa0)
    return [t, r.choice([0, 1, 1, 0x100, 0x2])]


S(0x5ae270, 'GUESS read_config_switches', 'thiscall', None, ret='al', gen=_g5ae270, note='batch37096')
