"""specs_s8801.py - hitreact batch 8801: ZFFActor::DieByForce (0x59f3e0), kill counters (0x5ab110, 0x5ab050,
0x5ab0b0), ZIKLNKOBJ::ActivateRagdoll (0x465760).

DieByForce: every virtual call is a recording stub. ZActor::DieByForce 0x4783f0, ZIKLNKOBJ::HitRagdoll 0x466c10, the
three counters, MYSTR c_str 0x4cc1d0 and MYSTR::~MYSTR 0x4cbec0 run as exe code in both builds (the first two are
batch 8800). GetRootTM (slot 0x80) fills the two stack outputs; the can-play stub (slot 0x37c) records the matrix it is
given (its two stack pointers are skipped). CalcTotalName (slot 0x1d8) is a hand stub: it makes the stack MYSTR point at
its own inline buffer (so the destructor frees nothing) and returns a heap MYSTR whose text pointer is fixed.
ActivateRagdoll: KillAllSounds 0x466ce0 is patched to a counting stub."""
import struct
from pilot import S
from wkit import rnd, stub, obj, fedge
from dkit import patch_jmp, seq_rec_stub


def _fbits(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _vec(c, n, vals):
    a = c.emu.alloc(4 * n + 16, 4)
    for i, v in enumerate(vals):
        c.emu.wf32(a + 4 * i, v)
    return a


def _name_stub(c, ms):
    """thiscall (out, full), ret 8: [out] = out + 4; count; eax = ms."""
    cnt = c.emu.alloc(4, 4)
    code = b'\x8b\x44\x24\x04'                      # mov eax,[esp+4]
    code += b'\x8d\x50\x04'                         # lea edx,[eax+4]
    code += b'\x89\x10'                             # mov [eax],edx
    code += b'\xff\x05' + struct.pack('<I', cnt)    # inc [cnt]
    code += b'\xb8' + struct.pack('<I', ms)         # mov eax,ms
    code += b'\xc2\x08\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _die(c):
    r = c.rng
    emu = c.emu
    fv = lambda: r.choice((r.uniform(-1, 1), r.uniform(-300, 300), 0.0, fedge(c)))
    mat = _vec(c, 9, [fv() for _ in range(9)])
    rp = _vec(c, 3, [r.uniform(-500, 500) for _ in range(3)])
    hdr = rnd(c, 0x80)
    emu.w32(hdr + 0x60, r.choice((0, 1, 25, r.randrange(-50, 400))) & 0xffffffff)
    emu.w32(hdr + 0x64, r.choice((0, 30, r.randrange(-50, 400))) & 0xffffffff)
    hdr2 = rnd(c, 0x80)
    hk = r.random()
    hdrs = [hdr, hdr2] if hk < 0.7 else ([0, hdr2] if hk < 0.85 else [hdr, 0])
    txt = emu.alloc(32, 4)
    emu.wbytes(txt, b'EnemySoldier#12\0')
    ms = emu.alloc(16, 4)
    emu.w32(ms, txt)
    bm = obj(c, 0x300, {0x3c: stub(c, 3)})
    slots = {
        0x588: stub(c, 0, ret=r.choice((0, 1, 2, 0x100, r.getrandbits(32)))),
        0x664: stub(c, 0),
        0x694: stub(c, 1),
        0x6e4: stub(c, 0),
        0x354: stub(c, 2, ret=r.choice((0, 0, 1, 0x100, 0xffffff01, 0xffffff00))),
        0x80: stub(c, 2, skip=(0, 1), ofills=[(0, 0, mat, 9), (1, 0, rp, 3)]),
        0x5a0: seq_rec_stub(c, 1, hdrs),
        0x1d8: _name_stub(c, ms),
        0x37c: stub(c, 7, skip=(3, 4), copy=(3, [(4 * i, 'd') for i in range(9)]),
                    ret=r.choice((0, 1, 0x100, 0xffffff01))),
        0x230: stub(c, 2),
    }
    a = obj(c, 0x980, slots)
    emu.w32(a + 0x6c, bm)
    for off in (0x7ba, 0x7be, 0x7c2, 0x7c6, 0x7ca):
        emu.w32(a + off, r.getrandbits(32))
    # owner / stats
    killer = r.choice((0, 0, 1, r.getrandbits(32)))
    if r.random() < 0.6:
        st = rnd(c, 0x900)
        if r.random() < 0.3:
            emu.w32(st + 0x300, 0x10000000)
        osd = rnd(c, 0x1d20)
        emu.w32(osd + 0x1d0f, st)
        own = rnd(c, 0x860)
        emu.w32(own + 0x852, osd)
        emu.w32(a + 0x92e, own)
    else:
        emu.w32(a + 0x92e, 0)
    team = rnd(c, 16)
    emu.w32(team + 4, r.choice((0, 0, 1, 2)))
    ko = obj(c, 0x80, {0x1e0: stub(c, 1, ret=r.choice((0, 1, 0x100, 0xffffff01)))})
    emu.w32(ko + 0x54, team)
    inner = obj(c, 0x100, {0x58: stub(c, 1, ret=ko)})
    rmv = r.choice((0.25, 0.5, 0.75, 0.5000001, float('nan'), r.random()))
    rm = obj(c, 0x200, {0x1c0: stub(c, 2, fldv=rmv)})
    emu.w32(rm + 0x9b, inner)
    emu.w32(0x70039c, rm)
    out = obj(c, 0x40, {0x2c: stub(c, 3, cdecl=True)})
    emu.w32(0x700390, obj(c, 0x40, {0x20: stub(c, 2, ret=out)}))
    pos = _vec(c, 3, [r.uniform(-500, 500) for _ in range(3)])
    force = _vec(c, 3, [fv() for _ in range(3)])
    s = _fbits(r.choice((1.0, 2.0, 0.2, fedge(c), r.uniform(-5, 50))))
    c.emu.mu.ctl_flush_tb()
    return [a, pos, force, s, killer]


S(0x59f3e0, 'ZFFActor::DieByForce', 'thiscall', ret=None, gen=_die)


def _ctr(c):
    st = rnd(c, 0x900)
    if c.rng.random() < 0.4:
        c.emu.w32(st + 0x300, 0x10000000)
    elif c.rng.random() < 0.3:
        c.emu.w32(st + 0x300, 0x10000001)
    return [st]


S(0x5ab110, 'kill counter +0x8b7', 'thiscall', ret=None, gen=_ctr)
S(0x5ab050, 'kill counter +0x8b3', 'thiscall', ret=None, gen=_ctr)
S(0x5ab0b0, 'kill counter +0x8af', 'thiscall', ret=None, gen=_ctr)


def _act(c):
    r = c.rng
    patch_jmp(c, 0x466ce0, stub(c, 0))
    bm = obj(c, 0x300, {0x30: stub(c, 4, ret=r.choice((0, 1, 0x100, r.getrandbits(32))))})
    a = obj(c, 0x300, {0x220: stub(c, 1)})
    c.emu.w32(a + 0x6c, bm)
    c.emu.mu.ctl_flush_tb()
    pick = lambda: r.choice((0, 1, 0x100, 0x101, r.getrandbits(32)))
    return [a, pick(), pick()]


S(0x465760, 'ZIKLNKOBJ::ActivateRagdoll', 'thiscall', ret='al', gen=_act)
