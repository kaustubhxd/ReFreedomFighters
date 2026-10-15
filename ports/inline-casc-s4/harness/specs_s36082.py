"""specs_s36082.py - cascade s4 batch 36082: 0x425170 (pump the message queue of a window until a flag is set)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g425170(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    this = obj(c, 0x40, {0x18: pystub(c, 3, this=True)})
    wnd = r.getrandbits(32) | 1
    e.wbytes(this + 0x10, bytes([r.choice([0, 0, 7])]))
    e.w32(this + 0x24, r.choice([0, 0, 0, 1]))
    found = r.random() < 0.8
    peeks = [r.choice([0, 1, 1, 1, 0, 1]) for _ in range(12)]
    pk = [0]
    gt = [0]

    def msg(em, p):
        return bytes(em.rbytes(p, 28))

    def find(em, rr):
        em.calllog.append(('FindWindow', em.arg32(0), em.arg32(1)))
        em.ret(eax=0x1234 if found else 0, argbytes=8)

    def peek(em, rr):
        k = pk[0]
        pk[0] += 1
        v = peeks[k % len(peeks)] if k < 60 else 0
        em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(28)))
        em.calllog.append(('Peek', msg(em, em.arg32(0)), em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(4)))
        em.ret(eax=v, argbytes=20)

    def get(em, rr):
        k = gt[0]
        gt[0] += 1
        em.calllog.append(('Get', msg(em, em.arg32(0)), em.arg32(1), em.arg32(2), em.arg32(3)))
        em.ret(eax=0 if k % 5 == 4 else 1, argbytes=16)

    def tr(em, rr):
        em.calllog.append(('Translate', msg(em, em.arg32(0))))
        em.ret(eax=1, argbytes=4)

    def dsp(em, rr):
        em.calllog.append(('Dispatch', msg(em, em.arg32(0))))
        if r.random() < 0.08:
            em.w32(this + 0x24, 1)
        em.ret(eax=0, argbytes=4)

    def slp(em, rr):
        em.calllog.append(('Sleep', em.arg32(0)))
        em.ret(eax=0, argbytes=4)
    e.stub_import('FindWindowA', find)
    e.stub_import('PeekMessageA', peek)
    e.stub_import('GetMessageA', get)
    e.stub_import('TranslateMessage', tr)
    e.stub_import('DispatchMessageA', dsp)
    e.stub_import('Sleep', slp)
    return [this, wnd]


S(0x425170, 'GUESS pump window messages until a flag is set', 'thiscall', None, ret=None, gen=_g425170, note='batch36082')
