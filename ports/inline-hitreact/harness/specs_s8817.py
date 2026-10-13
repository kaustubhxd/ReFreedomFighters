"""specs_s8817.py - hitreact batch 8817: ConstrainedParticleSystem::CollideLineBetweenParticles3 (0x5440b0). PSVECSubtract / vaddscalar /
vaddscalar4 / vscalar3 run as exe code. Patched to recording stubs: CollideSolidCappedCylinderAndTriangle 0x544330 (records both end
points, the radius and the face; returns contact / no contact from a per-case pattern) and PullTriangleCyl2 0x547080 (records PA, PB,
QA, QB contents, the weights, silent and id; moves PA.x by +1 so the order of the capsule passes is checked). The face list is an
iterator object (slot 0x4c start, slot 0x64 next) over 0-3 face records. The sausage tables at 0x6ec3d0 / 0x6ec40c / 0x6ec448 are the
exe's own values."""
import struct
from pilot import S
from wkit import rnd, obj
from dkit import patch_jmp


def _code(c, b):
    a = c.emu.alloc(len(b) + 16, 16)
    c.emu.wbytes(a, b)
    return a


def _seq_ret(c, vals, nargs):
    """thiscall/fastcall-agnostic: returns vals[k] (then 0) on the k-th call, pops 4*nargs; counts calls."""
    n = len(vals)
    tab = c.emu.alloc(4 * (n + 1), 4)
    for i, v in enumerate(vals + [0]):
        c.emu.w32(tab + 4 * i, v)
    cnt = c.emu.alloc(4, 4)
    code = b'\xa1' + struct.pack('<I', cnt) + b'\x3d' + struct.pack('<I', n) + b'\x76\x05\xb8' + struct.pack('<I', n)
    code += b'\x8b\x04\x85' + struct.pack('<I', tab) + b'\xff\x05' + struct.pack('<I', cnt) + b'\xc2' + struct.pack('<H', 4 * nargs)
    return _code(c, code)


def _collide_stub(c, hits):
    """fastcall (ecx a, edx b; r, sau, tri), ret 0xc: records a[0..2], b[0..2], r, tri; returns hits[k % len] in al."""
    n = len(hits)
    tab = c.emu.alloc(4 * n, 4)
    for i, h in enumerate(hits):
        c.emu.w32(tab + 4 * i, h)
    log = c.emu.alloc(4 * 8 * 40, 4)
    cnt = c.emu.alloc(4, 4)
    code = b'\x56\x57'                                                     # push esi; push edi
    code += b'\x8b\x3d' + struct.pack('<I', cnt)                           # mov edi,[cnt]
    code += b'\x83\xff\x27\x77\x30'                                        # cmp edi,39; ja skip (0x30 bytes)
    code += b'\x6b\xf7\x20\x81\xc6' + struct.pack('<I', log)               # imul esi,edi,32; add esi,log
    body = b''
    for j in range(3):
        body += b'\x8b\x41' + bytes([4 * j]) + b'\x89\x46' + bytes([4 * j])          # [esi+4j] = a[j]
        body += b'\x8b\x42' + bytes([4 * j]) + b'\x89\x46' + bytes([12 + 4 * j])     # [esi+12+4j] = b[j]
    body += b'\x8b\x44\x24\x0c\x89\x46\x18'                                # r (esp+4+8 pushed regs)
    body += b'\x8b\x44\x24\x14\x89\x46\x1c'                                # tri
    code = code[:-len(b'\x83\xff\x27\x77\x30') - 0] if False else code
    code = b'\x56\x57' + b'\x8b\x3d' + struct.pack('<I', cnt) + b'\x83\xff\x27\x77' + bytes([9 + len(body)])
    code += b'\x6b\xf7\x20\x81\xc6' + struct.pack('<I', log) + body
    code += b'\x8b\xc7\x31\xd2\xb9' + struct.pack('<I', n) + b'\xf7\xf1'   # eax = cnt; edx = cnt % n
    code += b'\x8b\x04\x95' + struct.pack('<I', tab)                       # eax = tab[edx]
    code += b'\xff\x05' + struct.pack('<I', cnt) + b'\x5f\x5e\xc2\x0c\x00'
    return _code(c, code)


def _pull_stub(c):
    """fastcall (ecx tri, edx PA; f, f, f, PB, wA, wB, QA, QB, sau, silent, id), ret 0x2c: records PA, PB, QA, QB contents, wA, silent, id
    into a ring of 40 entries; then PA.x += 1."""
    log = c.emu.alloc(4 * 16 * 40, 4)
    cnt = c.emu.alloc(4, 4)
    one = c.emu.alloc(4, 4)
    c.emu.wf32(one, 1.0)
    body = b''
    for j in range(3):
        body += b'\x8b\x42' + bytes([4 * j]) + b'\x89\x46' + bytes([4 * j])                    # PA (edx)
    for k, off in enumerate((0x10 + 8, 0x20 + 8, 0x24 + 8)):                                   # PB [esp+0x10], QA [esp+0x1c], QB [esp+0x20] (+8)
        pass
    # stack (after push esi, push edi): ret +8, f1 +0xc, f2 +0x10, f3 +0x14, PB +0x18, wA +0x1c, wB +0x20, QA +0x24, QB +0x28, sau +0x2c, silent +0x30, id +0x34
    for k, so in enumerate((0x18, 0x24, 0x28)):
        body += b'\x8b\x44\x24' + bytes([so])
        for j in range(3):
            body += b'\x8b\x48' + bytes([4 * j]) + b'\x89\x4e' + bytes([12 + 12 * k + 4 * j])
    body += b'\x8b\x44\x24\x1c\x89\x46\x30'      # wA
    body += b'\x8b\x44\x24\x30\x89\x46\x34'      # silent
    body += b'\x8b\x44\x24\x34\x89\x46\x38'      # id
    code = b'\x56\x57' + b'\x8b\x3d' + struct.pack('<I', cnt) + b'\x83\xff\x27\x77' + bytes([9 + len(body)])
    code += b'\x6b\xf7\x40\x81\xc6' + struct.pack('<I', log) + body
    code += b'\xf3\x0f\x10\x02\xf3\x0f\x58\x05' + struct.pack('<I', one) + b'\xf3\x0f\x11\x02'   # PA.x += 1
    code += b'\xff\x05' + struct.pack('<I', cnt) + b'\x5f\x5e\xc2\x2c\x00'
    return _code(c, code)


def _gen(c):
    r = c.rng
    emu = c.emu
    nf = r.choice((0, 1, 1, 2, 3))
    faces = []
    for i in range(nf):
        f = rnd(c, 0x80)
        faces.append(f)
    hits = [r.choice((0, 1, 0x100, 0x101)) for _ in range(r.choice((1, 3, 7, 16)))]
    patch_jmp(c, 0x544330, _collide_stub(c, hits))
    patch_jmp(c, 0x547080, _pull_stub(c))
    fl = obj(c, 0x80, {0x4c: _seq_ret(c, [0], 1), 0x64: _seq_ret(c, faces, 1)})
    holder = rnd(c, 0x40)
    emu.w32(holder + 0x14, fl if r.random() < 0.9 else 0)
    base = emu.alloc(0x34 * 16 + 0x40, 4)
    emu.wbytes(base, bytes(r.getrandbits(8) for _ in range(0x34 * 16 + 0x40)))
    for i in range(16):
        for k in range(3):
            emu.wf32(base + i * 0x34 + 0xc + 4 * k, r.uniform(-100, 100))
            emu.wf32(base + i * 0x34 + 0x24 + 4 * k, r.uniform(-5, 5))
    self = rnd(c, 0x80)
    emu.w32(self + 0xf, base)
    emu.w32(self + 0x28, 16)
    emu.w32(self + 0x5d, holder)
    emu.w8(self + 8, r.choice((0, 1)))
    emu.mu.ctl_flush_tb()
    return [self]


S(0x5440b0, 'CollideLineBetweenParticles3', 'thiscall', ret=None, gen=_gen)
