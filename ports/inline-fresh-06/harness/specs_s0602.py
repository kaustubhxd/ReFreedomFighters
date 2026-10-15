"""specs_s0602.py - fresh-06 batch 2 (docs/20-fresh-06.md). Exe callees are logging stubs that pop what the real one
pops (tools/rets.py); DBREAD/DBLK reads return random dwords in order. Objects are random bytes."""
from pilot import S
from helpers06 import rnd, hk, vt, obj, seq, rv, eng


def _loadinit(c):
    hk(c, 0x4e6330, 1, ecx=True)
    hk(c, 0x4e5e60, 0, ecx=True, fn=seq(rv(c)))
    hk(c, 0x4e5e40, 0, ecx=True, fn=seq(rv(c)))
    return [rnd(c, 0x200), rnd(c, 0x20)]


def _ctor(c):
    hk(c, 0x469870, 0, ecx=True)
    return [rnd(c, 0x100)]


def _inval(c):
    def o():
        return obj(c, 0x20, vt(c, 'v%d' % c.rng.getrandbits(8), {8: (0, 0)}))
    this = rnd(c, 0x100)
    for off in (0xa9, 0xa1, 0xa5):
        c.emu.w32(this + off, o())
    c.emu.w32(this + 0xb1, c.rng.choice([0, o()]))
    return [this]


def _evt(setter):
    def g(c):
        hk(c, 0x5003d0, 1, ecx=True, ret=rnd(c, 0x20))
        hk(c, setter, 1, ecx=True)
        arr = rnd(c, 0x20)
        ev = obj(c, 0x40, vt(c, 'ev', {0x4c: (0, arr)}))
        fac = obj(c, 0x20, vt(c, 'fac', {0x18: (1, c.rng.choice([0, ev, ev]))}))
        return [fac, c.rng.getrandbits(32), rnd(c, 8)]
    return g


def _light(c):
    this = obj(c, 0x40, vt(c, 'prim', {0x14c: (2, 0)}))
    return [this, rnd(c, 0x40), rnd(c, 0x40)]


def _zwinpic(c):
    hk(c, 0x4ee4e0, 0, ecx=True)
    hk(c, 0x45c510, 1, pop=0)
    hk(c, 0x4690b0, 2, pop=0)
    return [rnd(c, 0x100), c.rng.choice([0, 1, 4, 5, 7, c.rng.getrandbits(32)])]


def memset_hk(c):
    """memset (0x634d10, cdecl): the VCRUNTIME import has no stub in pe_emu, so the call is done here and logged."""
    def f(e, a):
        e.wbytes(a[0], bytes([a[1] & 0xff]) * a[2])
        return a[0]
    hk(c, 0x634d10, 3, pop=0, fn=f)


def _consume(c):
    memset_hk(c)
    c.emu.w32(0x71419c, c.rng.choice([0, obj(c, 0x20, vt(c, 'gc', {0: (1, 0)}))]))
    return [rnd(c, 0x10)]


def _remove(c):
    hk(c, 0x4daf20, 0, ecx=True, edx=True, ret=c.rng.getrandbits(32))
    hk(c, 0x498750, 4, ecx=True, ret=c.rng.getrandbits(32))
    g = rnd(c, 0x100)
    if c.rng.random() < 0.5:
        p = rnd(c, 0x20)
        c.emu.w32(p + 0xc, rnd(c, 0x40))
        c.emu.w32(g + 0x54, p)
    else:
        c.emu.w32(g + 0x54, 0)
    return [rnd(c, 0x40), c.rng.getrandbits(32), g, rnd(c, 0x20)]


def _ctrl(c):
    hk(c, 0x610100, 1, ecx=True)
    hk(c, 0x4e5e60, 0, ecx=True, fn=seq(rv(c)))
    return [rnd(c, 0x200), rnd(c, 0x20)]


def _setdim(c):
    this = obj(c, 0x100, vt(c, 'sa', {0x36c: (1, 0), 0x370: (0, 0)}))
    c.emu.w32(this + 0x93, c.rng.choice([0, rnd(c, 0x10)]))
    return [this, rnd(c, 8)]


def _marktex(c):
    tab = obj(c, 0x20, vt(c, 'tab', {0x60: (2, c.rng.getrandbits(32))}))
    rm = obj(c, 0x20, vt(c, 'rm', {0x138: (0, tab), 0x4c: (2, c.rng.getrandbits(32))}))
    eng(c, {0x9b: rm})
    return [rnd(c, 0x80), rnd(c, 0x10), rnd(c, 0x10)]


def _loadu32(c):
    this = rnd(c, 0x20)
    buf = rnd(c, 0x40)
    cur = buf + 4 * c.rng.randrange(8)
    c.emu.w32(this + 8, cur)
    c.emu.w32(this + 0xc, c.rng.choice([buf + 0x40, cur + 4, cur + 3, cur, buf]))
    # With no handler the original runs int3 (a crash); that path is not run, so no case faults (strict count rule).
    h = 1 if c.emu.r32(this + 8) + 4 > c.emu.r32(this + 0xc) else c.rng.choice([0, 1])
    if h:
        def f(e, r):
            e.calllog.append(('ovf',))
            e.ret(eax=0)
        c.emu.w32(0x7003b0, c.emu.stub_fn('ovf', f))
    else:
        c.emu.w32(0x7003b0, 0)
    return [this, rnd(c, 8)]


def _discam(c):
    this = obj(c, 0x100, vt(c, 'sa', {0x2c4: (0, obj(c, 0x20, vt(c, 'x', {0x330: (1, 0)})))}))
    c.emu.w32(this + 0x93, c.rng.choice([0, rnd(c, 0x10)]))
    eng(c, {0x190f: obj(c, 0x20, vt(c, 'm', {0xb8: (1, 0)}))})
    return [this]


def _ctor2(c):
    memset_hk(c)
    hk(c, 0x647fd0, 4, ecx=True)
    return [rnd(c, 0x10100)] + rv(c, 4)


def _projmarks(c):
    hk(c, 0x610100, 1, ecx=True)
    hk(c, 0x4e12f0, 2, ecx=True)
    hk(c, 0x4e12e0, 2, ecx=True)
    hk(c, 0x4e1b30, 0, ecx=True)
    return [rnd(c, 0x100), rnd(c, 0x20)]


def _seqend(c):
    hk(c, 0x634273, 2, pop=0)
    eng(c, {0x1907: c.rng.choice([0, obj(c, 0x20, vt(c, 'o', {0x14: (1, 0)}))])})
    this = rnd(c, 0x100)
    c.emu.w32(this + 0x90, c.rng.choice([0, rnd(c, 8)]))
    c.emu.w32(this + 0x94, c.rng.choice([0, rnd(c, 8)]))
    return [this]


S(0x4b16e0, 'CCutSequenceMove::LoadInit(DBREAD&) thiscall', 'thiscall', None, gen=_loadinit)
S(0x4a7960, 'ctor vtable 0x690114 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor)
S(0x5ef520, 'CMessageDialog::InvalidateView thiscall', 'thiscall', None, gen=_inval)
S(0x5516e0, 'Signature_i_EventTranslator_t::handleEventTranslation stdcall', 'stdcall', None, ret='eax', gen=_evt(0x5002f0))
S(0x5510a0, 'Signature_f_EventTranslator_t::handleEventTranslation stdcall', 'stdcall', None, ret='eax', gen=_evt(0x500360))
S(0x6565e0, 'ZPrimControlBase::GetLightSpotData thiscall', 'thiscall', None, gen=_light)
S(0x4faca0, 'ZWINPIC deleting dtor thiscall', 'thiscall', None, ret='eax', gen=_zwinpic)
S(0x560320, 'CFFMPGameControl_if::consume stdcall', 'stdcall', None, gen=_consume)
S(0x498960, 'ZGeomBuffer::RemoveGeoms thiscall', 'thiscall', None, ret='eax', gen=_remove)
S(0x566ea0, 'CController::CopyEventDataBlock thiscall', 'thiscall', None, gen=_ctrl)
S(0x4f75a0, 'ZScrollArea::SetDimensions(float*) thiscall', 'thiscall', None, gen=_setdim)
S(0x4c5820, 'ZMarkTextureObjGroup::Init thiscall', 'thiscall', None, ret='eax', gen=_marktex)
S(0x5f2ea0, 'SerialInfo_t::loaduint32 thiscall', 'thiscall', None, gen=_loadu32)
S(0x4f70a0, 'ZScrollArea::DisableCamera thiscall', 'thiscall', None, gen=_discam)
S(0x65bfe0, 'ctor vtable 0x6c4714 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor2)
S(0x45ba60, 'ZProjectMarks::CopyDataBlock(DBLK*) thiscall', 'thiscall', None, gen=_projmarks)
S(0x4b4160, 'CCutSequenceList::End thiscall', 'thiscall', None, gen=_seqend)
