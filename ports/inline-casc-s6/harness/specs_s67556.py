"""specs_s67556.py - cascade s6 batch 67556 (0x553690, stdcall(req) ret 4, return value unused). 0x5003d0 (hook) returns the count node (byte +4 0 / 1 / other, value negative / 0 / positive)
then the id node. The table (sys[0x9b]) slot 0x58 returns object A (slot 0x128) for the first lookup and object B (slots 0x2d0 / 0x358 / 0x360) for the second; slot 0x114 is a custom stub popping 16
bytes on its first call and 24 on its second (which writes the out variable at arg 4 and returns a word with garbage high bits); logger and assert hook as in the sibling specs."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g553690(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg2c(em, res_):
        em.calllog.append(('log', em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)
    x = obj(c, 0x20, {0x2c: e.stub_fn('recorder', lg2c)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=x)}))
    A = obj(c, 0x20, {0x128: pystub(c, 1, this=True)})
    B = obj(c, 0x20, {0x2d0: pystub(c, 2, this=True), 0x360: pystub(c, 1, this=True), 0x358: pystub(c, 1, this=True)})
    state = {'n': 0}
    locv = r.getrandbits(32)
    rv = r.getrandbits(32)

    def s114(em, res_):
        k = state['n']
        state['n'] += 1
        if k == 0:
            em.calllog.append(('t114a', tuple(em.arg32(i) for i in range(4))))
            em.ret(eax=0, argbytes=16)
        else:
            em.calllog.append(('t114b', tuple(em.arg32(i) for i in (0, 1, 2, 3, 5))))
            em.wbytes(em.arg32(4), locv.to_bytes(4, 'little'))
            em.ret(eax=rv, argbytes=24)
    sysobj(c, table_slots={0x114: e.stub_fn('recorder', s114),
                           0x58: pystub(c, 1, this=True, ret=lambda em, k: [A, B][min(k, 1)])})
    n1 = rnd(c, 0x10)
    e.wbytes(n1, r.choice([0, 1, 3, 0xffffffff, 0x80000000, 7]).to_bytes(4, 'little'))
    e.wbytes(n1 + 4, bytes([r.choice([0, 1, 1, 2, 0x80])]))
    n2 = rnd(c, 0x10)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: [n1, n2][min(k, 1)])
    return [rnd(c, 0x20)]


S(0x553690, 'GUESS apply_ui_state', 'stdcall', None, ret=None, gen=_g553690, note='batch67556')
