"""specs_s815.py - animation layer thread, batch 815: ZAnimFilePack accessors on a generated clip pack."""
from pilot import S, F
from anim_common import only_hooks, logged_fn, rnd, install_crt_str

NAMES = [b'Walk', b'walk_fwd', b'Run', b'UB_Hold_Rifle', b'UB_CC_Stand', b'Idle01', b'idle02', b'Crouch_Walk',
         b'HeadLook', b'Die_Back', b'run']
BONES = [b'Pelvis', b'Spine', b'Head', b'R_Hand', b'L_Hand', b'R_Foot', b'Neck', b'spine1']


def _cstr(e, p, n=64):
    return e.rbytes(p, n).split(b'\0')[0]


def _stricmp(e, res):
    a, b = _cstr(e, e.arg32(0)), _cstr(e, e.arg32(1))
    e.calllog.append(('_stricmp', a, b))
    la, lb = a.lower(), b.lower()
    e.ret(eax=0 if la == lb else (0xffffffff if la < lb else 1), argbytes=0)


def make_pack(c):
    """Returns (pack object, list of AnimHeader addresses, data base)."""
    e, r = c.emu, c.rng
    data = c.emu.alloc(0x4000, 16)
    e.wbytes(data, bytes(r.getrandbits(8) for _ in range(0x40)))
    names = c.emu.alloc(0x200, 4)
    noff, pos = [], 0
    for i, b in enumerate(BONES):
        e.w8(names + pos, (i * 7 + 3) & 0xff)
        e.wbytes(names + pos + 1, b + b'\0')
        noff.append(pos)
        pos += len(b) + 2
    cur = 0x40
    hdrs = []
    n = r.randint(0, 6)
    for i in range(n):
        h = data + cur
        nm = r.choice(NAMES)
        e.wbytes(h, bytes(r.getrandbits(8) for _ in range(0x90)))
        e.wbytes(h, nm + b'\0')
        e.w32(h + 0x44, i if r.random() < 0.85 else r.randint(0, 9))
        e.w32(h + 0x48, r.choice([-1, r.randint(0, 0x100)]) & 0xffffffff)
        e.w32(h + 0x4c, r.choice([0, r.randint(1, 0x100)]))
        cur += 0x90
        nb = r.randint(0, 4)
        bt = cur
        e.w32(h + 0x80, bt)
        e.w32(data + bt, nb)
        cur += 4 + 4 * nb
        for k in range(nb):
            ba = cur
            e.w32(data + bt + 4 + 4 * k, ba)
            e.w32(data + ba, r.choice(noff))
            e.w32(data + ba + 4, r.getrandbits(32))
            e.w16(data + ba + 8, r.randint(0, 300))
            cur += 0x10
        hdrs.append(h)
    # chunk header and data block
    hc = c.emu.alloc(0x200, 4)
    e.wbytes(hc, bytes(r.getrandbits(8) for _ in range(0x40)))
    kind = r.choice(['plain', 'ext'])
    extra = r.randint(0, 3)
    e.w32(hc + 4, {'plain': 0x80000000, 'ext': 0xc0000000, 'none': 0x1234}[kind] | r.getrandbits(8))
    e.w32(hc + 0x10, extra)
    L = hc + (0x14 + 4 * extra if kind == 'ext' else 0x10)
    e.w32(L, n)
    top = r.choice([0, 0x40000000, 0x80000000, 0xc0000000])
    toff = 8 if top == 0 else r.choice([0xc, 0x10])
    e.w32(L + 4, top | 0x55)
    e.w32(L + 8, toff)
    for i, h in enumerate(hdrs):
        e.w32(L + toff + 4 * i, h - data)
    e.w32(hc + 8, 0x80)
    e.wbytes(hc + 0x80, b'C01A.ANM\0')
    pk = rnd(c, 0x2c)
    e.w32(pk + 4, hc)
    e.w32(pk + 8, names)
    e.w32(pk + 0xc, data)
    e.w32(pk + 0x24, rnd(c, 0x10))
    if kind == 'none':
        c.vars['none'] = True
    return pk, hdrs, data


def _plain(c):
    only_hooks(c, {})
    install_crt_str(c)
    pk, _, _ = make_pack(c)
    return [pk]


def _hdrarg(c):
    only_hooks(c, {})
    pk, hdrs, data = make_pack(c)
    h = c.rng.choice(hdrs) if hdrs else data + 0x40
    if not hdrs:
        c.emu.w32(h + 0x80, 0)
        c.emu.w32(c.emu.r32(pk + 0xc), 0)
    return [pk, h]


def _byname(c):
    only_hooks(c, {})
    install_crt_str(c)
    r = c.rng
    pk, hdrs, data = make_pack(c)
    nm = c.emu.alloc(0x40, 4)
    s = r.choice(NAMES + [b'', b'*', b'Walk*', b'*Hold*', b'W*k', b'IDLE01', b'Missing'])
    c.emu.wbytes(nm, s + b'\0')
    return [pk, nm]


def _nr(c):
    only_hooks(c, {})
    pk, hdrs, _ = make_pack(c)
    return [pk, c.rng.choice([0, 1, 2, len(hdrs), -1, 7]) & 0xffffffff]


def _bai(c):
    only_hooks(c, {})
    pk, hdrs, data = make_pack(c)
    hs = [h for h in hdrs if c.emu.r32(data + c.emu.r32(h + 0x80)) > 0]
    if not hs:
        return [pk, data + 0x40, 0] if False else [pk, _fake_hdr(c, pk), 0]
    h = c.rng.choice(hs)
    return [pk, h, c.rng.randint(0, c.emu.r32(data + c.emu.r32(h + 0x80)) - 1)]


def _fake_hdr(c, pk):
    e = c.emu
    data = e.r32(pk + 0xc)
    h = rnd(c, 0x90)
    e.w32(h + 0x80, 0x3000)
    e.w32(data + 0x3000, 1)
    e.w32(data + 0x3004, 0x3010)
    return h


def _ban(c):
    only_hooks(c, {})
    install_crt_str(c)
    r = c.rng
    pk, hdrs, data = make_pack(c)
    h = r.choice(hdrs) if hdrs else _fake_hdr(c, pk)
    nm = c.emu.alloc(0x40, 4)
    c.emu.wbytes(nm, r.choice(BONES + [b'*Hand', b'head', b'X']) + b'\0')
    return [pk, h, nm]


def _ba(c):
    only_hooks(c, {})
    r = c.rng
    pk, hdrs, data = make_pack(c)
    e = c.emu
    ba = rnd(c, 0x10)
    e.w32(ba, r.choice([0, 7, 14, 20]))
    return [pk, ba]


def _dtor(c):
    only_hooks(c, {0x634273: logged_fn('delete', 0)})
    return [rnd(c, 0x2c), c.rng.choice([0, 1, 3, 2])]


S(0x4e5000, 'ZAnimFilePack::ZAnimFilePack', 'thiscall', None, ret='eax', gen=lambda c: [rnd(c, 0x2c)], note='batch815')
S(0x4e5050, 'ZAnimFilePack::~ZAnimFilePack', 'thiscall', None, ret='eax', gen=_dtor, note='batch815')
S(0x4e5080, 'ZAnimFilePack::CountAnimBones', 'thiscall', None, ret='eax', gen=_hdrarg, note='batch815')
S(0x4e50a0, 'ZAnimFilePack::CountAnims', 'thiscall', None, ret='eax', gen=_plain, note='batch815')
S(0x4e50c0, 'ZAnimFilePack::DoesAnimBelongTo', 'thiscall', None, ret='al', gen=_hdrarg, note='batch815')
S(0x4e5160, 'ZAnimFilePack::GetAnim(name)', 'thiscall', None, ret='eax', gen=_byname, note='batch815')
S(0x4e5310, 'ZAnimFilePack::GetAnimEvent', 'thiscall', None, ret='eax', gen=_hdrarg, note='batch815')
S(0x4e5330, 'ZAnimFilePack::GetAnimFileName', 'thiscall', None, ret='eax', gen=_plain, note='batch815')
S(0x4e5360, 'ZAnimFilePack::GetAnimNr', 'thiscall', None, ret='eax', gen=_nr, note='batch815')
S(0x4e53d0, 'ZAnimFilePack::GetBoneAnim(i)', 'thiscall', None, ret='eax', gen=_bai, note='batch815')
S(0x4e53f0, 'ZAnimFilePack::GetBoneAnim(name)', 'thiscall', None, ret='eax', gen=_ban, note='batch815')
S(0x4e5450, 'ZAnimFilePack::GetBoneAnimName', 'thiscall', None, ret='eax', gen=_ba, note='batch815')
S(0x4e5470, 'ZAnimFilePack::GetBoneAnimNrFrames', 'thiscall', None, ret='eax', gen=_ba, note='batch815')
S(0x4e5480, 'ZAnimFilePack::GetBoneId', 'thiscall', None, ret='al', gen=_ba, note='batch815')
S(0x4e54a0, 'ZAnimFilePack::GetFacialAnim', 'thiscall', None, ret='eax', gen=_hdrarg, note='batch815')
