"""specs_s35026.py - 0x424850 (ret='al'). USER32 imports stubbed in Python: PeekMessageA (5 args: hwnd and the flags recorded, fills the 0x1c-byte MSG with random bytes; non-zero for the first 0..3 calls),
GetMessageA (4 args, fills MSG, returns 0 in 1/6), TranslateMessage and DispatchMessageA (1 arg: MSG content recorded). Guard byte +0x2241 set in 1/4."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g424850(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    m = r.choice([0, 1, 2, 3])
    state = {'p': 0}
    gz = r.random() < 1 / 6

    def peek(em, rr):
        k = state['p']
        state['p'] += 1
        em.calllog.append(('Peek', em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(4)))
        em.wbytes(em.arg32(0), bytes((k * 37 + i * 11 + 5) & 0xff for i in range(0x1c)))
        em.ret(eax=1 if k < m else 0, argbytes=20)

    def get(em, rr):
        em.calllog.append(('Get', em.arg32(1), em.arg32(2), em.arg32(3), bytes(em.rbytes(em.arg32(0), 0x1c))))
        em.wbytes(em.arg32(0), bytes((0xa0 + i * 3 + state['p']) & 0xff for i in range(0x1c)))
        em.ret(eax=0 if (gz and state['p'] >= 1) else 1, argbytes=16)

    def tr(em, rr):
        em.calllog.append(('Translate', bytes(em.rbytes(em.arg32(0), 0x1c))))
        em.ret(eax=1, argbytes=4)

    def dp(em, rr):
        em.calllog.append(('Dispatch', bytes(em.rbytes(em.arg32(0), 0x1c))))
        em.ret(eax=0, argbytes=4)
    e.stub_import('PeekMessageA', peek)
    e.stub_import('GetMessageA', get)
    e.stub_import('TranslateMessage', tr)
    e.stub_import('DispatchMessageA', dp)
    me = rnd(c, 0x2300)
    e.wbytes(me + 0x2241, bytes([1 if r.random() < 0.25 else 0]))
    return [me, r.getrandbits(32)]


S(0x424850, 'GUESS pump window messages with re-entry guard', 'thiscall', None, ret='al', gen=_g424850, note='batch35026')
