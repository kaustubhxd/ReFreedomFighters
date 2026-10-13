"""specs_s13026.py - fresh-13 batch 26: 0x620910 GUESS stream/parser step. Cdecl (s, a, b, c), returns eax.
Parsers 0x626da0 / 0x626dd0 are Python hooks (cdecl, 10 words): they log the tag, a, s+0x8c, b, c and the s+0x118
pointer, write pa / len / ctx / kind (and sometimes pb) through the stack pointers, and return 0 / 1. ctx is 0, an
object whose +0x44 equals (s+0x8c)+0x44, or one that differs. Object s+0x8c has a cdecl +0x20 size function (logged);
0x620840 (4 args) returns 0 sometimes; 0x620cb0 / 0x61fbc0 (returns 0x12 sometimes) / 0x6204a0 logged; callback
s+0x88 is 0 or a logged cdecl stub; s+0x50 / +0xe4 / +0xe8 / +0x26c / a vary."""
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush, HOOKED  # noqa: F401


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=24, width=7)
    s = rnd(c, 0x280)
    o = rnd(c, 0x50)
    k44 = r.getrandbits(32)
    c.emu.w32(o + 0x44, k44)
    c.emu.w32(o + 0x20, logstub(c, log, 2, 1, ret=r.choice([0, 4, r.getrandbits(16)]), this=False, pop=False))
    c.emu.w32(s + 0x8c, o)
    ctxo = rnd(c, 0x50)
    c.emu.w32(ctxo + 0x44, k44 if r.random() < 0.5 else r.getrandbits(32))
    out = {'pa': r.choice([0, r.getrandbits(32)]), 'len': r.choice([0, r.getrandbits(32)]),
           'ctx': r.choice([0, 0, ctxo]), 'kind': r.choice([1, 1, 0, 0xffffffff, 2]),
           'pb': r.choice([None, r.getrandbits(32)])}
    ok = r.choice([0, 1, 1, 1, 1, 0x100])

    def _parse(tag):
        def h(e, rr):
            sp = e.reg('esp')
            w = [e.r32(sp + 4 + 4 * k) for k in range(10)]
            log.put(e, [tag] + w[0:5])
            e.w32(w[5], out['pa'])
            if out['pb'] is not None:
                e.w32(w[6], out['pb'])
            e.w32(w[7], out['len'])
            e.w32(w[8], out['ctx'])
            e.w32(w[9], out['kind'])
            e.ret(eax=ok)
        return h
    for a, t in ((0x626da0, 2), (0x626dd0, 3)):
        HOOKED.add(a)
        c.emu.hook(a, _parse(t))
    rets = [r.choice([0, 1, r.getrandbits(32), r.getrandbits(32)]) for _ in range(4)]
    k = {'i': 0}

    def _mk(e):
        v = rets[k['i'] % 4]
        k['i'] += 1
        return v
    loghook(c, log, 0x620840, 4, 4, ret=_mk, this=False, pop=False)
    loghook(c, log, 0x620cb0, 4, 5, this=False, pop=False)
    loghook(c, log, 0x61fbc0, 2, 6, ret=r.choice([0, 0x12, 0x12, 5]), this=False, pop=False)
    loghook(c, log, 0x6204a0, 1, 7, this=False, pop=False)
    c.emu.w32(s + 0x88, r.choice([0, logstub(c, log, 4, 8, this=False, pop=False)]))
    for off in (0x50, 0xe4, 0xe8):
        c.emu.w32(s + off, r.choice([0, 1]))
    c.emu.w32(s + 0x26c, r.choice([0, 1, 2]))
    flush(c)
    return [s, r.choice([0, 0, r.getrandbits(32)]), r.getrandbits(32), r.getrandbits(32)]


S(0x620910, 'FUN_00620910 (GUESS stream/parser step)', 'cdecl', None, ret='eax', gen=_gen,
  note='fresh13 batch13026; parsers write the out words; all callees logged')
