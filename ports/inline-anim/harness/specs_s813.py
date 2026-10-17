"""specs_s813.py - animation layer thread, batch 813: ZLNKOBJ::StartAnim, StopAllAnims."""
from pilot import S, F
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot, install_fmod


def _hdr(c):
    e, r = c.emu, c.rng
    h = rnd(c, 0x90)
    e.w32(h + 0x5c, r.randint(0, 50))
    e.w32(h + 0x6c, r.choice([30, 25, 15, 0, r.randint(1, 60)]))
    e.w32(h + 0x60, r.randint(0, 10))
    e.w32(h + 0x64, r.choice([r.randint(10, 200), 0, r.randint(0, 10)]))
    e.w32(h + 0x7c, r.choice([0, 1, 2, 3, 8, 0x10, 0x1b, 0x80000000, r.getrandbits(32)]))
    return h


def _start(c):
    only_hooks(c, {})
    install_fmod(c)
    e, r = c.emu, c.rng
    g = rnd(c, 0x60)
    clk = r.randint(0, 1 << 24)
    e.w32(g + 0x40, clk)
    e.w32(0x70039c, g)
    hdr = _hdr(c)
    ba = rnd(c, 0x80)
    e.w32(ba + 0x70, hdr)
    e.wf32(ba + 0x2c, r.choice([0.0, c.fv(0, 1)]))
    e.wf32(ba + 0x28, r.choice([1.0, c.fv(0, 2), 0.5]))
    e.wf32(ba + 0x30, c.fv(0, 30))
    e.wf32(ba + 0x34, r.choice([-1.0, -1.0, c.fv(0, 100)]))
    e.w32(ba + 0x44, r.choice([0, 0, 1]))
    # root bone with a clip
    rb = rnd(c, 0x80)
    rh = _hdr(c)
    e.w32(rb + 0x70, rh)
    e.w32(rb + 0x14, r.choice([8, 0, 8 | 0x200, r.getrandbits(32)]))
    e.w32(rb + 0xc, r.choice([r.randint(1, 120), 0, -5]))
    e.wf32(rb + 0x28, r.choice([1.0, c.fv(0, 2)]))
    e.wf32(rb + 0x1c, (clk - r.randint(0, 50000)) / 1024.0)
    tab = rnd(c, 0x18 * 4)
    e.w8(tab + 4, r.choice([0, 1, 1, 3]))
    e.w32(tab + 0x14, 0 if r.random() < 0.2 else rb)
    nb = r.randint(0, 6)

    def bonemap(e, res):
        a = e.arg32(0)
        e.calllog.append(('BoneIndex', a))
        e.ret(eax=0xffffffff if (a & 3) == 0 else (a & 0x1f), argbytes=4)
    file = vt_object(c, 0x40, {0x24: vslot('file.Count', 1, ret=nb),
                               0x2c: vslot('file.BoneAnim', 2, ret=lambda e, a: (a[1] * 0x10001 + 7) & 0xffffffff),
                               0x3c: vslot('file.BoneId', 1, ret=lambda e, a: (a[0] * 37 + 0xab00) & 0xffff)},
                     name='file')
    o = vt_object(c, 0x200, {0x268: vslot('vt268', 2), 0x2b4: bonemap,
                             0x350: vslot('TakeClip', 4, ret=lambda e, a: (a[2] & 1))}, nslots=0xe0, name='lnk')
    e.w32(o + 0x1c, tab)
    e.w32(o + 0x5c, file)
    return [o, ba, r.choice([0, 2, 0x10, 0x12, r.getrandbits(32)])]


def _stopall(c):
    only_hooks(c, {0x462510: logged_fn('ZBoneAnim::Destroy', 1)})
    e, r = c.emu, c.rng
    n = r.randint(0, 6)
    tab = rnd(c, 0x18 * n + 0x20)
    for i in range(n):
        e.w8(tab + 0x18 * i + 4, r.choice([0, 1, 3]))
        ba = rnd(c, 0x80)
        e.w32(ba + 0x70, _hdr(c))
        e.w32(tab + 0x18 * i + 0x14, ba)
    nodes = []
    for i in range(r.randint(0, 4)):
        nd = rnd(c, 0x80)
        e.w32(nd + 4 + 0x70, _hdr(c))
        nodes.append(nd)
    st = {'items': nodes[:], 'pos': 0}

    def begin(e, res):
        st['pos'] = 0
        e.calllog.append(('pool.begin',))
        e.ret(eax=0, argbytes=4)

    def nxt(e, res):
        v = st['items'][st['pos']] if st['pos'] < len(st['items']) else 0
        st['pos'] += 1
        e.calllog.append(('pool.next', v))
        e.ret(eax=v, argbytes=4)

    def rem(e, res):
        st['pos'] -= 1
        e.calllog.append(('pool.remove', st['items'].pop(st['pos'])))
        e.ret(eax=0, argbytes=4)
    pool = vt_object(c, 0x20, {0x4c: begin, 0x64: nxt, 0x44: rem}, name='pool')
    o = vt_object(c, 0x200, {0x274: vslot('vt274', 0), 0x340: vslot('EndMatBoneMotion', 2)}, nslots=0xe0, name='lnk')
    e.w32(o + 0x1c, tab)
    e.w32(o + 0x20, n)
    e.w32(o + 0x18, 0 if r.random() < 0.15 else pool)
    return [o, r.choice([0, 1, 0x100])]


S(0x464760, 'ZLNKOBJ::StartAnim', 'thiscall', None, ret='al', gen=_start, note='batch813')
S(0x464d00, 'ZLNKOBJ::StopAllAnims', 'thiscall', None, gen=_stopall, note='batch813')
