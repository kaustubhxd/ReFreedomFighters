"""specs_c102.py - climb thread batch 102: 0x59b350 GetSewerId, 0x5c3a90 COpenSewer::OpenLid,
0x59b3c0 ZFFLevelController::GetStartingSewerLid."""
import struct
from pilot import S
from ckit import rvt, obj, rnd, floats, wfloats, cstr

_LIDNAMES = [b'SewerLid_01', b'SewerLid_07', b'Lid12', b'Lid_3', b'X9', b'7', b'', b'Sewer_Lid_42', b'manhole_00']


def _named_geom(c, nm):
    """geom->slot 0x20() -> a; a->slot 0x20() -> b; b+4 = name (or null)."""
    e = c.emu
    b = rnd(c, 0x10)
    if nm is None:
        e.w32(b + 4, 0)
    else:
        e.w32(b + 4, cstr(e, nm) + (0 if nm else 0))
    a = obj(e, 'geomA', 0x10, {0x20: (0, lambda e, t, a, b=b: (b, None, ()))})
    return obj(e, 'geom', 0x10, {0x20: (0, lambda e, t, args, a=a: (a, None, ()))})


def _gsid(c):
    r = c.rng
    if r.random() < 0.1:
        return [0]
    nm = None if r.random() < 0.1 else r.choice(_LIDNAMES)
    # a few random bytes before short names, so the reads before the string are the same on both sides
    c.emu.alloc(4, 1)
    return [_named_geom(c, nm)]


S(0x59b350, 'ZFFLevelController::GetSewerId', 'stdcall', None, ret='eax', gen=_gsid, note='c102; ECX unused')


def _engine(c, geoms):
    """g_pSysInterface with +0x9b = engine db; db slot 0x58 maps a ref to geoms[ref] (0 if missing),
    slot 0x114 returns a 16-bit frame id (high bits random), slot 0x138 returns the scene com."""
    e = c.emu
    r = c.rng
    fid = r.getrandbits(32)

    def gref(e, t, a):
        return (geoms.get(a[0], 0), None, (a[0],))

    def frame(e, t, a):
        return (fid, None, (a[0], a[1], a[2], a[3]))
    names = {}

    def lookup(e, t, a):
        s = bytes(e.rbytes(a[0], 32)).split(b'\0')[0]
        ref = names.setdefault(s, c.vars.get('ref_' + s.decode(), r.getrandbits(16)))
        e.w32(a[1], ref)
        return (0, None, (s,))
    sc = obj(e, 'scenecom', 0x10, {0x88: (2, lookup)})
    db = obj(e, 'enginedb', 0x10, {0x58: (1, gref), 0x114: (4, frame), 0x138: (0, lambda e, t, a: (sc, None, ()))})
    sys_ = rnd(c, 0x100)
    e.mu.mem_write(sys_ + 0x9b, struct.pack('<I', db))
    e.w32(0x70039c, sys_)
    return db


def _geom128(c):
    return obj(c.emu, 'lidgeom', 0x10, {0x128: (3, None)})


def _openlid(c):
    r = c.rng
    e = c.emu
    geoms = {}
    sew = rnd(c, 16)
    ref = e.r32(sew + 4)
    if r.random() < 0.8:
        geoms[ref] = _geom128(c)
    _engine(c, geoms)
    self_ = rnd(c, 0x20)
    return [self_, 0 if r.random() < 0.1 else sew]


S(0x5c3a90, 'COpenSewer::OpenLid', 'thiscall', None, ret=None, gen=_openlid, note='c102; this unused')


def _gsl(c):
    r = c.rng
    e = c.emu
    e.unhook(0x59b3c0)   # specs_c103 hooks this address
    self_ = rnd(c, 0x1100)
    e.w8(self_ + 0x103f, 1 if r.random() < 0.05 else 0)
    if r.random() < 0.9:
        e.w32(self_ + 0x1050, 0)
    # level name and the sewer table (19 records of 18 bytes from +0xedb+8)
    lvl = r.choice([b'C01A', b'C02A', b'C03B', b'C05A'])
    e.wbytes(self_ + 0x48, lvl + b'\0')
    lids = [-1, -2, -3, 0, 1, 7, 12, 42, -5, 3]
    for i in range(19):
        rec = self_ + 0xedb + 8 + 0x12 * i
        nm = r.choice([b'C01A', b'C02A', b'C03B', b'C05A', b'C09A'])
        e.wbytes(rec, struct.pack('<I', cstr(e, nm)))
        e.wbytes(rec + 4, struct.pack('<b', r.choice(lids)))
        wfloats(e, rec + 5, [c.fv(-500, 500) for _ in range(3)])
    # game data: sewer list
    n = r.choice([0, 1, 2, 3, 5, 8])
    gd = rnd(c, 0xc6d + 9 * n + 16, 1)
    e.mu.mem_write(gd + 0xc69, struct.pack('<i', n))
    geoms = {}
    for k in range(n):
        ref = r.getrandbits(16) | 0x10000
        e.mu.mem_write(gd + 0xc6d + 9 * k + 4, struct.pack('<I', ref))
        if True:   # every record has a geometry: the exe calls slot 0x84 on the lookup result with no null check
            nm = r.choice([b'Lid_%02d' % r.choice([0, 1, 7, 12, 42, 3]), b'Lid', b'7'])
            pos = [c.fv(-50, 50) if r.random() < 0.8 else c.fv() for _ in range(3)]
            if r.random() < 0.1 and 'lastpos' in c.vars:
                pos = c.vars['lastpos']
            c.vars['lastpos'] = pos
            g = _lidgeom(c, nm, pos)
            geoms[ref] = g
    e.w32(0x7003b8, gd)
    # hero ground: ref of "HitmanGround" -> ground geom; ground->slot 0x20() -> g with slot 0x74 and +8 = a geom with matpos
    inner = rnd(c, 0x40)
    wfloats(e, inner, [c.fv(-2, 2) for _ in range(9)] + [c.fv(-50, 50) for _ in range(3)])

    def setmatpos(e, t, a):
        return (0, None, (floats(e, a[0], 9), floats(e, a[1], 3)))
    g = obj(e, 'groundinner', 0x20, {0x74: (2, setmatpos)})
    e.w32(g + 8, inner)
    ground = obj(e, 'ground', 0x10, {0x20: (0, lambda e, t, a, g=g: (g, None, ()))})
    gref = 0x20000 | r.getrandbits(8)
    geoms[gref] = ground
    c.vars['ref_HitmanGround'] = gref
    c.vars['ref_SewerController'] = 0x30000 | r.getrandbits(8)
    ctl = rnd(c, 0x20)
    _engine(c, geoms)
    holder = obj(e, 'eventdb', 0x10, {0xcc: (1, lambda e, t, a, ctl=ctl: (ctl, None, (a[0],)))})
    e.w32(0x70038c, holder)
    return [self_]


def _lidgeom(c, nm, pos):
    e = c.emu
    b = rnd(c, 0x10)
    e.w32(b + 4, cstr(e, nm))
    m = [c.fv(-2, 2) for _ in range(9)]   # precomputed so orig and port read the same values (no RNG draw inside a callee)

    def setlidmat(e, t, args):
        wfloats(e, args[0], m)
        wfloats(e, args[1], pos)
        return (0, None, ())
    a = obj(e, 'lidA', 0x10, {0x20: (0, lambda e, t, args, b=b: (b, None, ())), 0x74: (2, setlidmat)})

    def getpos(e, t, args, pos=pos):
        wfloats(e, args[0], pos)
        return (0, None, ())
    return obj(e, 'lid', 0x10, {0x20: (0, lambda e, t, args, a=a: (a, None, ())), 0x84: (1, getpos), 0x128: (3, None)})


S(0x59b3c0, 'ZFFLevelController::GetStartingSewerLid', 'thiscall', None, ret='eax', gen=_gsl,
  note='c102; GetSewerInfo, GetSewerId, OpenLid, GetMatPos and the in-place subtract run as original code')
