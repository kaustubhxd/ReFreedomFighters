"""specs_s1914.py - fresh slice 19, batch1914 (src/batch1914.cpp). Exe callees hooked by address with logging handlers
(pop counts checked against each callee's ret N); stack objects logged by content, never by address; USER32/KERNEL32
imports stubbed through the IAT."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt, _hk


def _r(c):
    return c.rng.getrandbits(32)


def _vh(c, name, nargs, eax=None, log_ecx=True):
    def h(em, r):
        em.calllog.append((name, 0, em.reg('ecx') if log_ecx else None, tuple(em.arg32(k) for k in range(nargs))))
        em.ret(eax=_r(c) if eax is None else (eax(em) if callable(eax) else eax), argbytes=4 * nargs)
    return h


def _g_57def0(c):
    e = c.emu
    rng = c.rng
    s = _rnd(c, 0x350)
    e.w32(s + 0xdc, rng.choice([2, 2, 2, 0, 1, 3]))
    rm = _rnd(c, 0x1910)
    e.w32(0x70039c, rm)
    e.w32(rm + 0x1907, _rnd(c, 0x1320))
    _hk(c, 0x57ece0, 'step', 1)
    _hk(c, 0x562c20, 'ZVideoSelector::OnCommand', 1)
    _hk(c, 0x57e930, 'fn_57e930', 0)
    _hk(c, 0x57d000, 'fn_57d000', 0)
    _hk(c, 0x634d22, 'crt copy', 3, pop=0)
    cmd = rng.choice([0x3ea, 0x3eb, 0x1388, 0x2b67, 0x1770, 0x3e9, 0x3ec, 0x1387, 0x1389, 0x176f, 0x2b66, 0, _r(c)])
    return [s, cmd]


def _g_64f9f0(c):
    e = c.emu
    rng = c.rng
    vals = [rng.choice([0.0, 0.0, -0.0, 1.5, 12.0, rng.uniform(-50, 50), float('nan')]) for _ in range(2)]
    ret = rng.choice([0, 1, 2, -1])

    def scan(em, r):
        em.calllog.append(('sscanf', 0x42ab0d, None, (em.arg32(0), em.arg32(1))))
        if ret >= 1:
            em.wf32(em.arg32(2), vals[0])
        if ret >= 2:
            em.wf32(em.arg32(3), vals[1])
        em.ret(eax=ret, argbytes=0)
    e.hook(0x42ab0d, scan)
    pre = bytes(c.rng.getrandbits(8) for _ in range(8))
    if rng.random() < 0.5:
        pre = struct.pack('<ff', vals[0], rng.choice([0.0, vals[1]]))

    def get(em, r):
        em.calllog.append(('fnt.100', 0, em.reg('ecx'), ()))
        em.wbytes(em.arg32(0), pre)
        em.ret(eax=0, argbytes=4)

    def put(em, r):
        em.calllog.append(('fnt.fc', 0, em.reg('ecx'), (em.rbytes(em.arg32(0), 8),)))
        em.ret(eax=0, argbytes=4)
    fnt = _rnd(c, 0x10)
    e.w32(fnt, _pyvt(c, {0xfc: put, 0x100: get}))
    s = _rnd(c, 0x110)
    e.w32(s + 0x104, fnt)
    logobj = _rnd(c, 16)

    def printf(em, r):
        em.calllog.append(('log.printf', 0x2c, None, tuple(em.arg32(k) for k in range(6))))
        em.ret(eax=0, argbytes=0)
    e.w32(logobj, e.fake_vtable('log', 16, {0x2c: printf}))
    lg = _rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (logobj, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    return [s, rng.choice([0, _r(c)])]


def _g_425170(c):
    e = c.emu
    rng = c.rng
    s = _rnd(c, 0x30)
    e.w32(s + 0x24, rng.choice([0, 0, 0, 1]))
    e.w32(s, _pyvt(c, {0x18: _vh(c, 'self.18', 3, eax=0)}))
    found = rng.choice([0, _r(c), 1])
    e.stub_import('FindWindowA', lambda em, r: (em.calllog.append(('FindWindowA', 0, None, (em.arg32(0), em.arg32(1)))),
                                                em.ret(eax=found, argbytes=8)))
    p_peek = rng.choice([0.0, 0.3, 0.7, 0.9])
    p_get = rng.choice([0.0, 0.5, 0.9])
    stop_at = rng.choice([1, 2, 5, 60, 10 ** 6])
    cnt = {'sleep': 0}
    msgs = [bytes(rng.getrandbits(8) for _ in range(0x1c)) for _ in range(4)]

    def peek(em, r):
        em.calllog.append(('PeekMessageA', 0, None, tuple(em.arg32(k) for k in range(1, 5))))
        em.wbytes(em.arg32(0), msgs[0])
        em.ret(eax=1 if rng.random() < p_peek else 0, argbytes=20)
    e.stub_import('PeekMessageA', peek)

    def get(em, r):
        em.calllog.append(('GetMessageA', 0, None, tuple(em.arg32(k) for k in range(1, 4))))
        em.wbytes(em.arg32(0), msgs[1])
        em.ret(eax=1 if rng.random() < p_get else 0, argbytes=16)
    e.stub_import('GetMessageA', get)

    def m1(name, k):
        def h(em, r):
            em.calllog.append((name, 0, None, (em.rbytes(em.arg32(0), 0x1c),)))
            em.wbytes(em.arg32(0), msgs[k])
            em.ret(eax=1, argbytes=4)
        return h
    e.stub_import('TranslateMessage', m1('TranslateMessage', 2))
    e.stub_import('DispatchMessageA', m1('DispatchMessageA', 3))

    def sleep(em, r):
        em.calllog.append(('Sleep', 0, None, (em.arg32(0),)))
        cnt['sleep'] += 1
        if cnt['sleep'] == stop_at:
            em.w32(s + 0x24, 1)
        em.ret(eax=0, argbytes=4)
    e.stub_import('Sleep', sleep)
    return [s, _r(c)]


def _g_54cdf0(c):
    e = c.emu
    rng = c.rng
    s = _rnd(c, 0x8030)
    n1 = rng.choice([0, 1, 3, 6, -1, -0x7fffffff])
    n2 = rng.choice([0, 1, 2, 5, -2])
    e.w32(s + 0x8014, n1 & 0xffffffff)
    e.w32(s + 0x8018, n2 & 0xffffffff)
    st = _rnd(c, 0x100)
    e.w32(s + 0x8021, st + rng.choice([0, 1, 4]))
    e.w32(s, _pyvt(c, {0x30: _vh(c, 'self.30', 0, eax=0)}))
    e.wbytes(0x713e18, bytes([rng.choice([0, 1, 0x80]), rng.choice([0, 0, 1])]))
    return [s]


S(0x57def0, 'FUN_0057def0 (menu OnCommand)', 'thiscall', None, ret='al', gen=_g_57def0, note='batch1914')
S(0x64f9f0, 'FUN_0064f9f0 (font size)', 'thiscall', None, ret=None, gen=_g_64f9f0, nan_heap=True,
  note='batch1914; void; stack pair by content')
S(0x425170, 'FUN_00425170 (debug window pump)', 'thiscall', None, ret=None, gen=_g_425170,
  note='batch1914; void; USER32/KERNEL32 via IAT stubs')
S(0x54cdf0, 'ZSynth::BuildFrame', 'thiscall', None, ret=None, gen=_g_54cdf0, note='batch1914; void; .data flags')
