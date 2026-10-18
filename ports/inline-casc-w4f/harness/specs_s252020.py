"""specs_s252020.py - hand specs (Sonnet-w4f): 0x425b10 token / account lookup."""
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g425b10(c):
    clear_hooks(c); seh_chain(c, c.rng.choice([0, 1, 2])); r = c.rng; em = c.emu
    sr = [seh_record(c, 2) for _ in range(14)]
    n = lambda emu, tag: sum(1 for x in emu.calllog if x[0] == tag)
    ok1, ok2, ok3, ok4 = [r.random() < 0.7 for _ in range(4)]
    E1 = r.choice([0x3f0, 0x3f0, 5]); E2 = r.choice([0x7a, 0x7a, 5]); q1 = r.random() < 0.1
    H1, H2 = r.choice([0x1234, 0x77, 0]), r.choice([0x4321, 0x88, 0]); L = r.choice([4, 0x20, 0x44])
    POOL = rnd(c, 0x100); SIDP = rnd(c, 0x40); HP = r.choice([0x5000, 0x6000])
    alloc_ok = r.random() < 0.85; nm = rnd(c, 0x40); dm = rnd(c, 0x40)
    def st(name, fn):
        def h(emu, cur):
            fn(emu)
            sr[hash(name) % 14](emu, 0)
        em.stub_import(name, h)
    def gct(emu): emu.calllog.append(('gct',)); emu.ret(eax=0xfffffffe, argbytes=0)
    def ott(emu):
        a = [emu.arg32(i) for i in range(4)]
        emu.calllog.append(('ott', a[0], a[1], a[2]))
        if ok1: emu.w32(a[3], H1)
        emu.ret(eax=1 if ok1 else 0, argbytes=16)
    def gle(emu):
        k = n(emu, 'gle'); emu.calllog.append(('gle',)); emu.ret(eax=(E1 if k == 0 else E2), argbytes=0)
    def gcp(emu): emu.calllog.append(('gcp',)); emu.ret(eax=0xffffffff, argbytes=0)
    def opt(emu):
        emu.calllog.append(('opt', emu.arg32(0), emu.arg32(1)))
        if ok2: emu.w32(emu.arg32(2), H2)
        emu.ret(eax=1 if ok2 else 0, argbytes=12)
    def gti(emu):
        k = n(emu, 'gti'); a = [emu.arg32(i) for i in range(5)]
        emu.calllog.append(('gti', a[0], a[1], a[2], a[3]))
        if k == 0:
            emu.w32(a[4], L); emu.ret(eax=1 if q1 else 0, argbytes=20)
        else:
            if ok3: emu.w32(a[2], SIDP)
            emu.ret(eax=1 if ok3 else 0, argbytes=20)
    def gph(emu): emu.calllog.append(('gph',)); emu.ret(eax=HP, argbytes=0)
    def ha(emu):
        emu.calllog.append(('ha', emu.arg32(0), emu.arg32(1), emu.arg32(2)))
        emu.ret(eax=POOL if alloc_ok else 0, argbytes=12)
    def las(emu):
        a = [emu.arg32(i) for i in range(7)]
        emu.calllog.append(('las', a[0], a[1] == SIDP, a[2] == nm, a[3] == dm, a[4], a[5]))
        emu.w32(a[6], 3); emu.wbytes(a[2], b'user\0')
        emu.ret(eax=1 if ok4 else 0, argbytes=28)
    def ch(emu): emu.calllog.append(('ch', emu.arg32(0))); emu.ret(eax=1, argbytes=4)
    def hf(emu):
        emu.calllog.append(('hf', emu.arg32(0), emu.arg32(1), emu.arg32(2) == POOL)); emu.ret(eax=1, argbytes=12)
    for nme, f in (('GetCurrentThread', gct), ('OpenThreadToken', ott), ('GetLastError', gle), ('GetCurrentProcess', gcp), ('OpenProcessToken', opt),
                   ('GetTokenInformation', gti), ('GetProcessHeap', gph), ('HeapAlloc', ha), ('LookupAccountSidA', las), ('CloseHandle', ch), ('HeapFree', hf)):
        st(nme, f)
    return [nm, 0x40, r.getrandbits(32), r.getrandbits(32)]


S(0x425b10, 'GUESS hand port 0x425b10', 'fastcall', None, ret='eax', gen=g425b10, note='batch252020')


def g656260(c):
    clear_hooks(c); r = c.rng; em = c.emu
    R32 = lambda emu, k: r.getrandbits(32)
    T = rnd(c, 0x40); VT = rnd(c, 0x200); em.w32(T, VT)
    kind = r.choice([0, 1, 2, 3, 3, 4, 7, 0xffffffff])
    sizes = [r.choice([0, 1, 3, 4, 0x20, 0x41, 0x80]) for _ in range(3)]
    REC = rnd(c, 0x40); IDX = r.getrandbits(32)
    for q, off in enumerate((0x118, 0x11c, 0x120)):
        em.w32(VT + off, pystub(c, 0, this=True, ret=sizes[q], side=lambda emu, k, q=q: emu.calllog.append(('sz', q))))
    em.w32(0x7003b0, em.stub_fn('hook3', lambda emu, cur: (emu.calllog.append(('hook3',)), emu.ret(eax=r.getrandbits(32), argbytes=0))))
    def memset_(emu, cur):
        d, v, n = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        emu.calllog.append(('memset', v, n)); emu.wbytes(d, bytes([v & 0xff]) * n); emu.ret(eax=d, argbytes=0)
    em.stub_import('memset', memset_)
    def s50(emu, k):
        n = emu.arg32(1); p = emu.arg32(0)
        emu.calllog.append(('s50', n, bytes(emu.rbytes(p, min(n, 0x100))) if n <= 0x100 else b'big'))
    em.w32(VT + 0x50, pystub(c, 2, this=True, nullflag=(0,), ret=IDX, side=s50))
    em.w32(VT + 0xc, pystub(c, 1, this=True, ret=REC, side=lambda emu, k: emu.calllog.append(('s0c', emu.arg32(0) == IDX))))
    return [T, kind]


S(0x656260, 'GUESS hand port 0x656260', 'thiscall', None, ret='eax', gen=g656260, note='batch252020')
