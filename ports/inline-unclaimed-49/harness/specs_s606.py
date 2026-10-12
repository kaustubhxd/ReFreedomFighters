"""specs_s606.py - area 49 batch 606: CAction::FindAction (0x4a07c0).
Callees: 0x4cc850 (wildcard match, fastcall) hooked by address with a table fixed per run; the CRT _stricmp is the import at
0x676414 (stub_import, a case-insensitive compare). The action object, its [+0x10]->[+8] manager, the global manager at
0x70038c and the candidates are fake objects whose handlers answer from tables fixed in the setup, so the original and the
port see the same values. Both paths are exercised: this+0x63 zero (the walk) and non-zero (the list at this+0x102).
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402
import serial_stubs as ss  # noqa: E402

MGR_GLOBAL = 0x70038c
NAMES = [b'Fire', b'fire', b'Reload', b'RELOAD', b'Scope', b'scope', b'Jump']


def _cstr(c, text):
    a = c.emu.alloc(len(text) + 1, 4)
    c.emu.wbytes(a, text + b'\x00')
    return a


def _setup(c):
    r = c.rng
    k = r.randint(1, 4)
    # the candidates: slot 0x14 returns the candidate's name pointer (or 0; the match needs it nonzero); the name at +0x76,
    # id at +0x48, flag at +0x106
    nm = r.choice(NAMES)
    cands = []
    for _ in range(k):
        pick = (nm.swapcase() if r.random() < 0.5 else nm) if r.random() < 0.6 else r.choice(NAMES)
        ptr = _cstr(c, pick) if r.random() < 0.9 else 0
        fn = (lambda vv: lambda e, rr: e.ret(eax=vv, argbytes=0))(ptr)
        obj = c.emu.fake_object('cand', 0x120, nslots=0x60, slots={0x14: fn})
        c.emu.w32(obj + 0x76, ptr)
        c.emu.w32(obj + 0x48, r.choice((-1, 0, 1, 2)) & 0xffffffff)
        c.emu.w32(obj + 0x106, r.choice((0, 0, 1, 2)))
        cands.append(obj)

    # the manager at [0x70038c]: slot 0xcc (cur) returns candidate cur
    def cc(e, rr):
        e.calllog.append(('mgr.cc', 0xcc, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=cands[e.arg32(0) % k], argbytes=4)
    mgr = c.emu.fake_object('mgr', 0x40, nslots=0x60, slots={0xcc: cc})
    c.emu.w32(MGR_GLOBAL, mgr)

    # the object at this+0x44 slot 0x128 (three args): may write a list pointer into the slot
    L = c.emu.alloc(4 + 4 * k, 4)
    c.emu.w32(L, k)
    for i, obj in enumerate(cands):
        c.emu.w32(L + 4 + 4 * i, obj)
    fill_list = r.random() < 0.5

    def h128(e, rr):
        e.calllog.append(('act.128', 0x128, e.reg('ecx'), (e.arg32(0), e.arg32(1), e.arg32(2))))
        if fill_list:
            e.w32(e.arg32(1), L)
        e.ret(eax=0, argbytes=12)

    # manager at [this+0x44]+0x10 -> +8 is the object with slots 0x4c and 0x5c
    state = {'n': 0}

    def h4c(e, rr):
        e.calllog.append(('y.4c', 0x4c, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)

    def h5c(e, rr):
        e.calllog.append(('y.5c', 0x5c, e.reg('ecx'), (e.arg32(0),)))
        n = state['n']
        state['n'] = n + 1
        if n < k:
            e.w32(e.arg32(0), 1)
            e.ret(eax=n, argbytes=4)
        else:
            e.w32(e.arg32(0), 0)
            e.ret(eax=0, argbytes=4)
    y = c.emu.fake_object('y', 0x40, nslots=0x60, slots={0x4c: h4c, 0x5c: h5c})
    xa = c.emu.alloc(0x20, 16)
    c.emu.w32(xa + 8, y)
    x = c.emu.fake_object('x', 0x80, nslots=0x60, slots={0x128: h128})
    c.emu.w32(x + 0x10, xa)

    # wildcard match: fixed sequence per run
    m4cc = [r.choice((0, 0, 1)) for _ in range(64)]   # wildcard results, consumed in call order
    mi = {'i': 0}

    def h4cc(e, rr):
        v = m4cc[mi['i'] % len(m4cc)]
        mi['i'] += 1
        e.ret(eax=v, argbytes=0)
    c.emu.hook(0x4cc850, h4cc)

    c.emu.stub_import('_stricmp', lambda e, rr: e.ret(eax=_cmp_ci(e, e.arg32(0), e.arg32(1)), argbytes=0))

    self_ = c.emu.alloc(0x200, 16)
    c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x200)))
    c.emu.w8(self_ + 0x63, r.choice((0, 1, 1)))
    c.emu.w32(self_ + 0x44, x)
    c.emu.w32(self_ + 0x102, 0 if r.random() < 0.5 else L)
    c.emu.w8(self_ + 0x5e, 0)
    cnt7e = r.choice((0, 0, 1))   # the in-object list when the 0x128 call leaves the slot empty: count 0 or 1, entry a candidate
    c.emu.w32(self_ + 0x7e, cnt7e)
    if cnt7e:
        c.emu.w32(self_ + 0x82, cands[0])
    name = _cstr(c, nm) if r.random() < 0.9 else 0
    id_ = r.choice((-1, 0, 1, 2))
    flag = r.choice((0, 1, 2))
    return self_, name, 0, id_ & 0xffffffff, flag


def _cmp_ci(e, a, b):
    def rd(p):
        out = bytearray()
        for i in range(0x40):
            ch = e.rbytes(p + i, 1)[0]
            if ch == 0:
                break
            out.append(ch)
        return bytes(out).lower()
    x, y = rd(a), rd(b)
    return (x > y) - (x < y) & 0xffffffff


def _gen(c):
    return list(_setup(c))


S(0x4a07c0, 'CAction::FindAction', 'thiscall', None, ret='eax', gen=_gen)   # the matched entry (or 0) is compared
