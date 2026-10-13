"""specs_f0707.py - fresh slice 17, batch 7."""
from pilot import S
from specs_f0101 import _rnd, _vt, _hook, _obj
from specs_f0202 import _assert_hook


def _g49c4d0(c):
    e = c.emu
    self_o = _rnd(c, 0x30)
    words = []
    for _ in range(c.rng.randint(0, 4)):
        words.append(c.rng.getrandbits(32))                       # record header
        k = c.rng.randint(1, 4)
        for j in range(k):
            w = c.rng.choice([0, c.rng.getrandbits(32), c.rng.getrandbits(3), 0x1000]) & ~1
            words.append(w | (1 if j == k - 1 else 0))
    lst = _rnd(c, 0x10 + 4 * len(words) + 8)
    for i, w in enumerate(words):
        e.w32(lst + 0x10 + 4 * i, w)
    e.w32(self_o + 0x1d, lst)
    e.w32(self_o + 0x19, 4 + len(words))
    db = _obj(c, 0x10, _vt(c, 'db', 0x20, {0x54: (1, 4, True)}))
    eng = _rnd(c, 0x100)
    e.w32(eng + 0x9b, db)
    e.w32(0x70039c, eng)
    _hook(c, 0x49c420, 2, 8)
    return [self_o, _rnd(c, 8)]


def _g5298d0(c):
    _hook(c, 0x5167d0, 0, 0)
    return [_rnd(c, 0x140)]


def _build(glob):
    def g(c):
        e = c.emu
        e.w32(glob, 0 if c.rng.random() < 0.7 else c.rng.getrandbits(32))

        def res(e, r):
            v = e.reg('ecx')
            e.calllog.append(('reserve', e.rbytes(v, 13), e.arg32(0)))
            e.w32(v, 0x7000 + e.arg32(0)); e.w32(v + 4, 0x8000)
            e.ret(eax=c.rng.getrandbits(32), argbytes=4)
        e.hook(0x59a9b0, res)
        e.hook(0x4ff9d0, lambda e, r: (e.calllog.append(('dtor', e.rbytes(e.reg('ecx'), 13))), e.ret(eax=c.rng.getrandbits(32))))

        def fill(e, r):
            v = e.arg32(0)
            e.calllog.append(('fill', e.reg('ecx'), e.rbytes(v, 13)))
            e.w32(v + 8, 0x9000)
            e.ret(eax=c.rng.getrandbits(32), argbytes=4)
        return [_obj(c, 0x10, e.fake_vtable('o', 0x10, {0x1c: fill}))]
    return g


def _g560010(c):
    e = c.emu
    vals = [c.rng.choice([0, 5, -1, -0x80000000, c.rng.getrandbits(32)]) & 0xffffffff for _ in range(2)]
    cells = [_rnd(c, 4), _rnd(c, 4)]
    for a, v in zip(cells, vals):
        e.w32(a, v)

    def get(e, r):
        i = e.arg32(0)
        e.calllog.append(('get', e.reg('ecx'), i))
        e.ret(eax=cells[i & 1], argbytes=4)
    e.hook(0x5003d0, get)
    tgt = _rnd(c, 0x60)
    holder = _rnd(c, 0x2c30)
    e.w32(holder + 0x2c21, tgt)
    e.w32(0x7003b8, holder)
    arg = _rnd(c, 8)
    return [_rnd(c, 8), arg]


def _g4ca790(c):
    e = c.emu
    rd = _rnd(c, 8)
    b1, b2 = _rnd(c, 4), _rnd(c, 4)
    e.w8(b1, c.rng.choice([3, 0x43, 0xc3, 0xff, 4, 0]))
    e.w8(b2, c.rng.choice([4, 0x44, 0xff, 3, 0x84]))
    e.w32(rd, b1)
    sv = 0 if c.rng.random() < 0.2 else e.cstr(''.join(chr(c.rng.randint(0x21, 0x7e)) for _ in range(c.rng.randint(0, 20))))

    def rbool(e, r):
        e.calllog.append(('bool', e.reg('ecx')))
        e.w32(rd, b2)
        e.ret(eax=c.rng.getrandbits(32))

    def rstr(e, r):
        e.calllog.append(('str', e.reg('ecx')))
        e.ret(eax=sv)
    e.hook(0x4e5ef0, rbool)
    e.hook(0x4e5ea0, rstr)
    e.hook(0x41e290, lambda e, r: (e.calllog.append(('new', e.arg32(0))), e.ret(eax=e.alloc(e.arg32(0) + 8, 4, 0xab))))
    if c.rng.random() < 0.3:
        e.w32(rd, b2)
    return [_rnd(c, 0x50), rd]


def _g498650(c):
    e = c.emu
    _assert_hook(c)
    base = _rnd(c, 0x70 * 4)
    t = _rnd(c, 8)
    e.w32(t + 4, base)
    self_o = _rnd(c, 0x20)
    e.w32(self_o + 0x14, t)
    idx = [c.rng.randint(0, 3) for _ in range(c.rng.randint(0, 4))] + [0xffffffff]

    def rd18(e, r):
        p, n = e.arg32(0), e.arg32(1)
        v = idx.pop(0) if idx else 0xffffffff
        e.w32(p, v)
        e.calllog.append(('read', e.reg('ecx'), n, v))
        e.ret(eax=c.rng.getrandbits(32), argbytes=8)
    rd = _obj(c, 0x10, e.fake_vtable('rd', 0x10, {
        0x0c: lambda e, r: (e.calllog.append(('blk', e.reg('ecx'), e.arg32(0))), e.ret(eax=c.rng.getrandbits(32), argbytes=4)),
        0x34: lambda e, r: (e.calllog.append(('tag', e.reg('ecx'), e.arg32(0))), e.ret(eax=c.rng.getrandbits(32), argbytes=4)),
        0x18: rd18}))
    e.hook(0x4dbbe0, lambda e, r: (e.calllog.append(('load', e.reg('ecx'), e.arg32(0))), e.ret(eax=c.rng.choice([0, 1, 0x100, 0x2201]), argbytes=4)))
    return [self_o, rd]


N = 'fresh 17 batch 7'
S(0x49c4d0, 'CListUser::ConvertOffsetsToRefs(const unsigned int*)', 'thiscall', None, ret=None, gen=_g49c4d0, note=N + '; 0x49c420 hooked (ret 8)')
S(0x5298d0, 'GUESS FUN_5298d0 (constructor)', 'thiscall', None, ret='eax', gen=_g5298d0, note=N + '; member ctor 0x5167d0 hooked; SEH frame not reproduced')
S(0x5577d0, 'GUESS FUN_5577d0 (one-time build, global 0x713e2c)', 'thiscall', None, ret=None, gen=_build(0x713e2c), note=N + '; local vector logged by content (13 bytes); SEH frame not reproduced')
S(0x603850, 'OpaqueUserType_t::buildCMM()', 'thiscall', None, ret=None, gen=_build(0x724698), note=N + '; same shape, global 0x724698')
S(0x560010, 'GUESS FUN_560010 (set active slot on (*0x7003b8)+0x2c21)', 'thiscall', None, ret=None, gen=_g560010, note=N + '; 0x5003d0 hooked')
S(0x4ca790, 'ZSetZDefine::CopyEventDataBlock(DBREAD&)', 'thiscall', None, ret=None, gen=_g4ca790, note=N + '; DBREAD bool/char* and __builtin_new hooked')
S(0x498650, 'GUESS FUN_498650 (load 0x70-byte entries by index)', 'thiscall', None, ret=None, gen=_g498650, note=N + '; 0x4dbbe0 hooked; assert hook set')
