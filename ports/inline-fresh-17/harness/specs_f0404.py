"""specs_f0404.py - fresh slice 17, batch 4."""
from pilot import S, F
from specs_f0101 import _rnd, _vt, _hook, _obj
from specs_f0202 import _assert_hook


def _g63ac10(c):
    e = c.emu
    self_o = _rnd(c, 0x20)
    k = c.rng.randint(0, 3)

    def mkblock():
        b = _rnd(c, 0x10 + 3 * 0x1000 + 4)
        e.w16(b + 2, c.rng.choice([0xffff, 0xffff, 0, 1, 2]))
        return b
    blocks = [mkblock() for _ in range(k)]
    for i, b in enumerate(blocks):
        e.w32(b + 8, blocks[(i + 1) % k] if (i + 1 < k or c.rng.random() < 0.6) else 0)
    e.w32(self_o + 8, blocks[c.rng.randrange(k)] if k else 0)
    newb = mkblock()
    ok = c.rng.choice([0, 1, 0x100, 0xff01])

    def grow(e, r):
        e.calllog.append(('grow', e.reg('ecx')))
        if ok & 0xff:
            e.w32(self_o + 8, newb)
        e.ret(eax=ok)
    e.hook(0x63b1c0, grow)
    return [self_o]


def _g5f5390(c):
    e = c.emu
    _assert_hook(c)
    self_o = _rnd(c, 0x10)
    cnt = c.rng.randint(1, 8)
    arr = _rnd(c, 8 * (cnt + 1))
    for i in range(cnt + 1):
        e.w8(arr + 8 * i + 4, c.rng.choice([0, 4, 4, 1, 3, 0xff]))
        e.w32(arr + 8 * i, _obj(c, 0x10, _vt(c, 'old%d' % i, 12, {0x28: (0, 0, True)})))
    e.w32(self_o, arr)
    e.w32(self_o + 4, cnt)
    e.w32(self_o + 8, c.rng.randint(0, cnt))
    _hook(c, 0x42ab62, 1, 0, lecx=False)
    fac = _obj(c, 0x10, _vt(c, 'fac', 12, {0x24: (0, 0, True)}))
    return [self_o, fac]


def _g4e6c10(c):
    e = c.emu
    self_o = _rnd(c, 0x20)
    first = c.rng.randint(0, 40)          # n >= 0 keeps the list pointer inside the block
    count = c.rng.choice([0, 1, 2, 7, 16, 33, -1, -5])
    align = c.rng.choice([1, 2, 4, 8, 16, 3, 0, 6])
    if count < 0:               # a negative count only with an empty pool (n == 0), so the list pointer stays in the block
        first, align = 0, c.rng.choice([1, 2, 4, 8, 16])

    def new(e, r):
        sz = e.arg32(0)
        p = e.alloc(min(sz, 0x4000) + 0x200, 4, 0xab) if sz < 0x4000 or sz > 0xfff00000 else 0
        if sz >= 0x4000 and sz <= 0xfff00000:
            p = e.alloc(0x200, 4, 0xab)
        e.calllog.append(('new', sz))
        e.ret(eax=p)
    e.hook(0x41e290, new)
    return [self_o, first & 0xffffffff, count & 0xffffffff, align & 0xffffffff]


def _g656190(c):
    e = c.emu
    recs = {}
    hs = [c.rng.getrandbits(31) | 1 for _ in range(c.rng.randint(0, 5))]
    for i, h in enumerate(hs):
        r = _rnd(c, 0x10)
        e.w32(r + 8, hs[i + 1] if i + 1 < len(hs) else 0)
        recs[h] = r

    def s0c(e, _):
        h = e.arg32(0)
        if h not in recs:
            r = _rnd(c, 0x10)
            recs[h] = r
        e.calllog.append(('rec', e.reg('ecx'), h))
        e.ret(eax=recs[h], argbytes=4)

    def s64(e, _):
        h, a = e.arg32(0), e.arg32(1)
        n = c.rng.getrandbits(31) | 1
        e.calllog.append(('copy', e.reg('ecx'), h, a, n))
        e.ret(eax=n, argbytes=8)
    self_o = _obj(c, 0x20, e.fake_vtable('pc', 0x20, {0x0c: s0c, 0x64: s64}))
    return [self_o, hs[0] if hs else 0, c.rng.getrandbits(32)]


def _g4fa990(c):
    e = c.emu
    self_o = _obj(c, 0xb0, _vt(c, 'sb', 0xd8, {0x358: (0, 0, True)}))
    e.wf32(self_o + 0xa7, c.rng.choice([0.0, 5.0, -3.5, 100.0, c.rng.uniform(-50, 150)]))
    e.w32(self_o + 0xab, c.rng.choice([0, 10, 100, -5, c.rng.getrandbits(32)]))
    d = c.rng.choice([0.0, -0.0, 1.0, -10.0, 60.0, -0.5, 0.25, float('nan'), c.rng.uniform(-200, 200)])
    return [self_o, F(d)]


def _g5f0750(c):
    e = c.emu
    self_o = _rnd(c, 0x90)
    n = c.rng.randint(0, 4)
    buf = _rnd(c, 12 * 6)
    end = buf + 12 * n
    e.w32(self_o + 0x7c, buf)
    e.w32(self_o + 0x80, 0 if c.rng.random() < 0.1 else end)
    e.w32(self_o + 0x84, end if c.rng.random() < 0.4 else buf + 12 * 6)

    def grow(e, r):
        p = e.arg32(1)
        e.calllog.append(('grow', e.reg('ecx'), e.arg32(0), e.r32(p), e.r32(p + 4), e.r32(p + 8)))
        e.ret(eax=c.rng.getrandbits(32), argbytes=8)
    e.hook(0x5f0af0, grow)
    return [self_o, c.rng.getrandbits(32)]


N = 'fresh 17 batch 4'
S(0x63ac10, 'ZDrawArray<ZArrayBlock, ZArrayBlock, ZArrayBlock>::Add()', 'thiscall', None, ret='eax', gen=_g63ac10, note=N + '; grow 0x63b1c0 hooked')
S(0x5f5390, 'GUESS FUN_5f5390 (slot pool get)', 'thiscall', None, ret='eax', gen=_g5f5390, note=N + '; printf 0x42ab62 hooked; assert hook set')
S(0x4e6c10, 'CMemPool::Init(int, int, int)', 'thiscall', None, ret=None, gen=_g4e6c10, note=N + '; __builtin_new 0x41e290 hooked')
S(0x656190, 'ZPrimControlBase::CopyPrim(unsigned int, unsigned int)', 'thiscall', None, ret='eax', gen=_g656190, note=N)
S(0x4fa990, 'ZScrollbar::UpdateBarPos(float)', 'thiscall', None, ret=None, gen=_g4fa990, note=N + '; float heap word', nan_heap=True)
S(0x5f0750, 'ZCredits::Parse(const char*)', 'thiscall', None, ret=None, gen=_g5f0750, note=N + '; naked (uninitialised third word); grow 0x5f0af0 hooked, record logged by value')
