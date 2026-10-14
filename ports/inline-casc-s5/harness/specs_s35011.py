"""specs_s35011.py - 0x424d90. Imports stubbed in Python (all stdcall): USER32 RegisterWindowMessageA (1 arg, random id), WS2_32 WSAStartup (2 args: version recorded, data buffer filled with random bytes except the
version word 0x0202, returns 0), gethostbyname (1 arg, returns 0 in half the cases), inet_addr (1 arg, random), gethostbyaddr (3 args; arg 1 and 2 recorded, dword at +4 of the buffer recorded).
The base constructor 0x42acc0 runs as exe code. Object is random bytes; globals 0x700390 / 0x6fd930 compared as memory."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g424d90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ids = {'rw': r.getrandbits(32) | 1, 'ia': r.getrandbits(32), 'gn': 0 if r.random() < 0.5 else r.getrandbits(32) | 1, 'ga': r.getrandbits(32)}
    junk = bytes(r.getrandbits(8) for _ in range(0x190))

    def rw(em, rr):
        em.calllog.append(('RegisterWindowMessageA', em.arg32(0)))
        em.ret(eax=ids['rw'], argbytes=4)

    def wsa(em, rr):
        buf = em.arg32(1)
        em.calllog.append(('WSAStartup', em.arg32(0)))
        em.wbytes(buf, junk)
        em.w32(buf, 0x0202 | (junk[2] << 16) | (junk[3] << 24))
        em.ret(eax=0, argbytes=8)

    def gn(em, rr):
        em.calllog.append(('gethostbyname', em.arg32(0)))
        em.ret(eax=ids['gn'], argbytes=4)

    def ia(em, rr):
        em.calllog.append(('inet_addr', em.arg32(0)))
        em.ret(eax=ids['ia'], argbytes=4)

    def ga(em, rr):
        em.calllog.append(('gethostbyaddr', em.r32(em.arg32(0) + 4), em.arg32(1), em.arg32(2)))
        em.ret(eax=ids['ga'], argbytes=12)
    e.stub_import('RegisterWindowMessageA', rw)
    e.stub_import('WSAStartup', wsa)
    e.stub_import('gethostbyname', gn)
    e.stub_import('inet_addr', ia)
    e.stub_import('gethostbyaddr', ga)
    return [rnd(c, 0x40)]


S(0x424d90, 'GUESS network object constructor', 'thiscall', None, ret='eax', gen=_g424d90, note='batch35011')
