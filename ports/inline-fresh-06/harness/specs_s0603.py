"""specs_s0603.py - fresh-06 batch 3 (docs/20-fresh-06.md). The error handler at 0x7003b0 is always set, so the
original's int3 (no handler) is never reached: those crash paths are not exercised (no case faults)."""
from pilot import S
from helpers06 import rnd, hk, vt, cvt, obj, seq, rv, eng, logger, handler, zero


def _zgate(c):
    hk(c, 0x43de70, 0, ecx=True)
    hk(c, 0x45c510, 1, pop=0)
    hk(c, 0x4690b0, 2, pop=0)
    this = rnd(c, 0x100)
    c.emu.w32(this + 0x52, c.rng.choice([0, obj(c, 0x10, vt(c, 'o', {0: (1, 0)}))]))
    return [this, c.rng.choice([0, 1, 4, 5, 7, c.rng.getrandbits(32)])]


def _blk(c, free):
    b = rnd(c, 0x20)
    c.emu.wbytes(b + 2, b'\xff\xff' if not free else bytes([c.rng.getrandbits(8), c.rng.choice([0, 0xff, 3])]))
    return b


def _drawadd(c):
    hk(c, 0x63b440, 0, ecx=True, ret=c.rng.choice([0, 1, 0x100, 0xffffff00 | c.rng.getrandbits(8)]))
    hk(c, 0x63b050, 0, ecx=True, ret=c.rng.getrandbits(32))
    this = rnd(c, 0x40)
    n = c.rng.choice([0, 1, 2, 3, 5])
    bl = [_blk(c, c.rng.random() < 0.3) for _ in range(n)]
    for i, b in enumerate(bl):
        # the list ends in null or loops back to the first block (a loop to a later block never ends: not a case)
        nxt = bl[i + 1] if i + 1 < n else c.rng.choice([0, bl[0]])
        c.emu.w32(b + 8, nxt)
    c.emu.w32(this + 8, bl[0] if bl else 0)
    return [this]


def _sndcopy(c):
    hk(c, 0x45d5b0, 1, ecx=True)
    hk(c, 0x44bcf0, 1, ecx=True)
    eng(c, {0x1a9f: c.rng.choice([0, 1, c.rng.getrandbits(32)])})
    src = obj(c, 0x40, vt(c, 'src', {0x1e0: (1, c.rng.choice([0, 1, 0x100, 0xff]))}))
    this = rnd(c, 0x40)
    c.emu.w32(this + 0x18, c.rng.choice([0, rnd(c, 0x10)]))
    return [this, src]


def _drawlocal(c):
    e = rnd(c, 0x40)
    c.emu.w32(e + 0xc, c.rng.choice([0, rnd(c, 0x40)]))
    hk(c, 0x64d030, 4, ecx=True, ret=e)
    hk(c, 0x4de420, 0, ecx=True, edx=True)
    return [rnd(c, 0x20), rnd(c, 0x20), rnd(c, 0x40), rnd(c, 0x10),
            c.rng.choice([0xff, 0xffffffff, 0x1ff, c.rng.getrandbits(32), 0])]


def _collapse(c):
    n = c.rng.randrange(0, 40)
    s = bytes(c.rng.choice(b'ab \n\r\t x') for _ in range(n)) + b'\0'
    a = c.emu.alloc(len(s) + 8, 4)
    c.emu.wbytes(a, s + bytes(c.rng.getrandbits(8) for _ in range(8)))
    return [a]


def _comstart(c):
    com = obj(c, 0x10, cvt(c, 'com', {0x34: (2, c.rng.getrandbits(32)),
                                      0x30: (4, c.rng.choice([0, 0, c.rng.getrandbits(32)]))},
                           pops={0x34: 8, 0x30: 16}))
    hk(c, 0x54f2b0, 0, ecx=True, edx=True, ret=c.rng.getrandbits(32))
    this = rnd(c, 0x6400)
    c.emu.w32(this + 0x63ec, com)
    c.emu.w32(this + 0x75, c.rng.choice([0, 1, 2, 3, 4, 0xffffffff, c.rng.getrandbits(32)]))
    return [this]


def _chain(c):
    nodes = [rnd(c, 0x140) for _ in range(c.rng.randrange(1, 5))]
    for i, n in enumerate(nodes):
        c.emu.w32(n + 0x9c, nodes[i + 1] if i + 1 < len(nodes) else 0)
        c.emu.w32(n + 0x12a, c.rng.choice([0x1000 * i, c.rng.getrandbits(32), 0xfffff000]))
        c.emu.w32(n + 0x12e, c.rng.choice([0, 0x100, 0x2000, c.rng.getrandbits(32)]))
    pick = c.rng.choice(nodes)
    a = (c.emu.r32(pick + 0x12a) + c.rng.choice([0, 1, 0xff, 0x100, 0x1fff, -1])) & 0xffffffff
    return [nodes[0], c.rng.choice([a, c.rng.getrandbits(32)])]


def _loadfile(c):
    hk(c, 0x634273, 2, pop=0)
    hk(c, 0x41e290, 1, pop=0, ret=rnd(c, 0x10))
    fs = obj(c, 0x10, vt(c, 'fs', {0x30: (2, c.rng.choice([0, 1, 0x40, 0xffffffff, 0x80000000])),
                                  0x60: (5, c.rng.getrandbits(32))}))
    c.emu.w32(0x700394, fs)
    this = rnd(c, 0x20)
    c.emu.w32(this + 4, c.rng.choice([0, rnd(c, 8)]))
    return [this, rnd(c, 0x10)]


def _attach(c):
    e = rnd(c, 0x20)
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x58: (1, e)}))})
    hk(c, 0x4dcbb0, 1, ecx=True)
    this = obj(c, 0x80, vt(c, 'self', {0x68: (2, 0)}))
    c.emu.wbytes(this + 0x58, bytes([c.rng.choice([0, 0, 1, 0x80])]))
    c.emu.w32(this + 0x54, c.rng.choice([0, 1, 2, 0x101]))
    c.emu.w32(this + 0x59, obj(c, 0x10, vt(c, 'act', {0x290: (4, 0)})))
    return [this]


def _alloc(c):
    hk(c, 0x63b710, 1, ecx=True, ret=c.rng.choice([0xffffffff, 0, c.rng.getrandbits(32)]))
    logger(c, 1)
    return [rnd(c, 0x80), c.rng.choice([0, 1, 15, 16, 17, -16, 0x7ffffff8, c.rng.getrandbits(32)]) & 0xffffffff]


def _vminit(c):
    hk(c, 0x600280, 5, ecx=True, ret=c.rng.choice([0, 0x100, 1, c.rng.getrandbits(32)]))
    logger(c, 2)
    handler(c)
    return [rnd(c, 0x100)] + rv(c, 4)


def _matload(c):
    hk(c, 0x440e10, 1, ecx=True)
    n = c.rng.choice([0, 1, 2, 3, 0xffffffff, 0x80000000])
    ids = rv(c)

    def wn(e, a, n=n):
        e.w32(a[0], n)
    st = [0]

    def wid(e, a):
        e.w32(a[0], ids[st[0] % 8])
        st[0] += 1
    lg = obj(c, 0x10, vt(c, 'lg', {0x48: (1, wn), 0x40: (1, wid)}))
    eng(c, {0x9b: obj(c, 0x10, vt(c, 'rm', {0x58: (1, seq(rv(c)))}))})
    this = rnd(c, 0x80)
    c.emu.w32(this + 0x5c, obj(c, 0x10, vt(c, 'list', {4: (1, 0)})))
    return [this, lg]


def _numentries(c):
    e = rnd(c, 0x60)
    c.emu.wbytes(e + 2, c.rng.choice([b'\0\0', b'\0\0', b'\x01\0', b'\0\x80']))
    handler(c)
    this = obj(c, 0x10, vt(c, 'pc', {0xc: (1, e)}))
    return [this, c.rng.getrandbits(32), c.rng.choice(list(range(0, 18)) + [0xffffffff, c.rng.getrandbits(32)])]


def _sndenv(c):
    e = eng(c, {0x1a9f: c.rng.choice([0, obj(c, 0x10, vt(c, 's', {0xcc: (1, 0)}))])})
    logger(c, 1)
    this = c.rng.choice([rnd(c, 0x80), e - 0x10])   # second form: this+0x50 is engine+0x40 (same address)
    return [this, rnd(c, 8), rnd(c, 8)]


S(0x452fa0, 'ZGATE deleting dtor thiscall', 'thiscall', None, ret='eax', gen=_zgate)
S(0x63ade0, 'ZDrawArray<ZGeomDrawEntry>::Add thiscall', 'thiscall', None, ret='eax', gen=_drawadd)
S(0x44bca0, 'ZSNDOBJ::CopyData(const ZGEOM*) thiscall', 'thiscall', None, gen=_sndcopy)
S(0x65f460, 'ZDrawBuffer::DrawBaseGeomLocal thiscall', 'thiscall', None, gen=_drawlocal)
S(0x620120, 'collapse whitespace (GUESS) cdecl', 'cdecl', None, ret='eax', gen=_collapse)
S(0x54c320, 'COM start (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_comstart)
S(0x5ffe20, 'chain lookup 28-byte records (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_chain)
S(0x49e0e0, 'load whole file (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_loadfile)
S(0x4b8da0, 'ZAttachGeomToBone::FrameUpdate thiscall', 'thiscall', None, gen=_attach)
S(0x63b7e0, 'ZDrawBase::AllocSprites(int) thiscall', 'thiscall', None, ret='eax', gen=_alloc)
S(0x6001e0, 'VMImageInfo_t::initNewStateContext thiscall', 'thiscall', None, ret='eax', gen=_vminit)
S(0x455020, 'ZMaterialDescGroup::Load(ZLoadGame*) thiscall', 'thiscall', None, ret='al', gen=_matload)
S(0x656fe0, 'ZPrimControlGC::GetNumEntries thiscall', 'thiscall', None, ret='eax', gen=_numentries)
S(0x4b0ba0, 'CCutSequenceSoundEnvironment::Run thiscall', 'thiscall', None, gen=_sndenv)
