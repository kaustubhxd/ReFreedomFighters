"""specs_s812.py - animation layer thread, batch 812: ZLNKOBJ::EndMatBoneMotion. CCom calls are hooked (the CCom
lives on the stack, so only its contents passed to SetVal are logged)."""
from pilot import S, F
from anim_common import only_hooks, rnd, vt_object, vslot


def _cstr(e, p, n=40):
    b = e.rbytes(p, n)
    return b.split(b'\0')[0]


def _sendmsg(e, res):
    e.calllog.append(('SendMsg', e.reg('ecx'), e.arg32(0), e.arg32(1), e.arg32(2) if 0x20000000 <= e.arg32(2) < 0x30000000 else 'stack'))
    e.ret(eax=0, argbytes=12)


def _emb(c):
    e, r = c.emu, c.rng

    def h(name, n):
        def f(e, res):
            a = [e.arg32(k) for k in range(n)]
            if name == 'SetValStr':
                a = [_cstr(e, a[0]), _cstr(e, a[1])]
            elif name == 'SetValInt':
                a = [_cstr(e, a[0]), a[1]]
            e.calllog.append(('CCom.' + name,) + tuple(a))
            e.ret(eax=0, argbytes=4 * n)
        return f
    only_hooks(c, {0x4d2280: h('ctor', 0), 0x4d39a0: h('SetValStr', 2), 0x4d3ab0: h('SetValInt', 2),
                   0x4d2330: h('dtor', 0)})
    n = r.randint(2, 8)
    tab = rnd(c, 0x18 * n + 0x30)
    bas = []
    for i in range(3):
        ba = rnd(c, 0x80)
        e.w32(ba + 0x44, r.choice([1, 1, 2, 0, r.getrandbits(32)]))
        e.wbytes(ba + 0x4c, b'clip%d\0' % i)
        bas.append(ba)
    for i in range(n):
        e.w8(tab + 0x18 * i + 4, r.choice([0, 1, 1, 3, r.getrandbits(8)]))
        e.w32(tab + 0x18 * i + 0x14, r.choice(bas))
    defs = rnd(c, 0x30 * n + 0x40)
    for i in range(n):
        e.w8(defs + 0x30 * i + 0x2f, r.choice([0, 3, 1]))
        e.w32(defs + 0x30 * i + 0xc, (r.randint(0, i - 1) if i > 0 and r.random() < 0.8 else -1) & 0xffffffff)   # acyclic chain
    # pool of pooled ZBoneAnims (node = [flags] + object)
    nodes = []
    for i in range(r.randint(0, 4)):
        nd = rnd(c, 0x80)
        e.w32(nd + 4 + 0x44, r.choice([0xfffffffe, 0, 1]))
        nodes.append(nd)
    st = {'pos': 0}

    def begin(e, res):
        st['pos'] = 0
        e.calllog.append(('pool.begin',))
        e.ret(eax=0, argbytes=4)

    def nxt(e, res):
        v = nodes[st['pos']] if st['pos'] < len(nodes) else 0
        st['pos'] += 1
        e.calllog.append(('pool.next', v))
        e.ret(eax=v, argbytes=4)
    pool = vt_object(c, 0x20, {0x4c: begin, 0x64: nxt}, name='pool')
    file = vt_object(c, 0x20, {0x30: vslot('file.BoneClip', 2, ret=r.choice([0, r.getrandbits(32), r.getrandbits(32)]))}, name='file')
    geom = rnd(c, 0x80)
    o = vt_object(c, 0x200, {0x2cc: vslot('GetBoneDefs', 0, ret=defs), 0x2bc: vslot('vt2bc', 1, ret=0x55),
                             0x350: vslot('vt350', 4, ret=r.choice([0, 1, 1])), 0x130: _sendmsg,
                             0x344: vslot('AnimDone', 2), 0x34c: vslot('StartPooled', 2)}, nslots=0xe0, name='lnk')
    e.w32(o + 0x1c, tab)
    e.w32(o + 0x20, n)
    e.w32(o + 0x18, 0 if r.random() < 0.2 else pool)
    e.w32(o + 0x5c, file)
    e.w32(o + 8, geom)
    e.w8(o + 0x70, r.choice([0, 0, 1]))
    return [o, r.randint(0, n - 1), r.choice([0, 1, 1, 0x100])]


S(0x4627d0, 'ZLNKOBJ::EndMatBoneMotion', 'thiscall', None, gen=_emb, note='batch812')
